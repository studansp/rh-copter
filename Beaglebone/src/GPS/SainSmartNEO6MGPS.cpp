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

#define GPGGA_ATTEMPTS 50
#define MAXCOUNT 5000

SainSmartNEO6MGPS::SainSmartNEO6MGPS(string namebuf, char address)
: AbstractI2CDevice(namebuf, address)
{
	_gpgga = new SainSmartNEO6MGPSGPGGA();
}

void SainSmartNEO6MGPS::Refresh(std::string input)
{
	//The GPS is going to throw back a number of strings
	//We will throw them away until we get the string we want
	for(int i=0;i<GPGGA_ATTEMPTS;i++)
	{
		std::string read = getNextString();

		if (boost::starts_with(read, "$GPGGA"))
		{
			_gpgga->Refresh(read);
			_validity = _gpgga->IsValid();

			break;
		}
	}
}

SainSmartNEO6MGPS::~SainSmartNEO6MGPS()
{
}

//Get the next message from the GPS
//Basically it will throw valid data or 0xFF until it is ready
//Not sure exactly how often this is, but the following seems to produce
//without attempting too many potentially faulty reads

std::string SainSmartNEO6MGPS::getNextString()
{
	string returnString = "";

	if(InitReadWrite())
	{
		char readChar[1];
		bool inSequence = false;

		for(int i=0;i<=MAXCOUNT;i++)
		{
			Read(readChar, 1);

			if(inSequence)
			{
				if(readChar[0]=='$')
				{
					break;
				}
				else if(readChar[0]!=0xFF)
				{
					returnString += readChar[0];
				}
			}
			else if(readChar[0]=='$') //Start of sequence
			{
				inSequence = true;
				returnString="$";
			}

			if(i==MAXCOUNT)
			{	//If we haven't found anything by this point, something is wrong
				break;
			}
		}


		EndReadWrite();
	}

	return returnString;
}
