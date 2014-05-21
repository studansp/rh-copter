/*
 * SainSmartNEO6MGPS.cpp
 *
 *  Created on: May 18, 2014
 *      Author: phillip
 */

#include "SainSmartNEO6MGPS.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "GPRMC/SainSmartNEO6MGPSGPRMC.h"
#include "GPGGA/SainSmartNEO6MGPSGPGGA.h"
using namespace std;

#ifndef NULL
#define NULL ((void *)0)
#endif

SainSmartNEO6MGPS::SainSmartNEO6MGPS(string namebuf, char address)
: AbstractI2CDevice(namebuf, address)
{
	_gprmc = new SainSmartNEO6MGPSGPRMC();
	_gpgga = new SainSmartNEO6MGPSGPGGA();
}

void SainSmartNEO6MGPS::ReadData()
{
	bool foundMc=false, foundGa=false;

	for(int i=0;i<20;i++) //Try 20 reads
	{	//TODO Figure out how to actually interface with the device...
		std::string read = getNextString();

		cout << "{" << read << "}" << endl;

		if (boost::starts_with(read, "$GPRMC"))
		{
			_gprmc->Refresh(read);
			foundMc=true;
			break;
		}

		else if (boost::starts_with(read, "$GPGGA"))
		{
			_gprmc->Refresh(read);
			foundGa=true;
			break;
		}

		if(foundMc&&foundGa)
			break;
	}
}

SainSmartNEO6MGPS::~SainSmartNEO6MGPS()
{
}

std::string SainSmartNEO6MGPS::getNextString()
{
	string returnString = "";

	if(InitRead())
	{
		//Per datasheet, write to initiate transfer
		char initBuf[1];
		initBuf[0] = 0xFF;

		Write(initBuf, 1);

		char readChar[1];

		for(int i=0;i<=1024;i++)
		{
			Read(readChar, 1);

			if(readChar[0]=='$') //Start of sequence
			{
				returnString+='$';


				for(int k=0;k<100;k++) //NMEA should not be greater than 80
				{
					Read(readChar, 1);

					if(readChar[0]!='$')
					{
						returnString += readChar;
					}
					else
					{
						break;
					}
				}

				break;
			}

			if(i==1024)
			{	//If we haven't found anything by this point, something is wrong
				break;
			}
		}


		EndRead();
	}

	return returnString;
}
