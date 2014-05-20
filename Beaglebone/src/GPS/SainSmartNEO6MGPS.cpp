/*
 * SainSmartNEO6MGPS.cpp
 *
 *  Created on: May 18, 2014
 *      Author: phillip
 */

#include "SainSmartNEO6MGPS.h"
#include <iostream>
#include <stdio.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/fcntl.h>
#include <stropts.h>
#include <math.h>
#include <unistd.h>
#include <boost/algorithm/string/predicate.hpp>

using namespace std;

SainSmartNEO6MGPS::SainSmartNEO6MGPS(string namebuf, char address)
{
	_namebuf = namebuf;
	_address = address;
}

void SainSmartNEO6MGPS::ReadData()
{
	for(int i=0;i<20;i++) //Try 20 reads
	{	//TODO Figure out how to actually interface with the device...
		std::string read = getNextString();

		cout << "{" << read << "}" << endl;

		if (boost::starts_with(read, "$GPRMC"))
		{
			if(_gprmc!=NULL)
			{
				_gprmc->Refresh(read);
			}
			else
			{
				_gprmc = new GPRMC(read);
			}
			break;
		}
	}
}

SainSmartNEO6MGPS::~SainSmartNEO6MGPS()
{
}

std::string SainSmartNEO6MGPS::getNextString()
{
	int file;

	if((file = open(_namebuf.c_str(), O_RDWR)) < 0)
	{
		cout << "Failed to open file";
		return "";
	}

	if(ioctl(file, I2C_SLAVE, 0x42) < 0)
	{
		cout << "Unable to open IO";
		return "";
	}

	char readChar[1];
	string returnString = "";
	int bytesRead;

	for(int i=0;i<=1024;i++)
	{
		bytesRead = read(file, readChar, 1);

		if(readChar[0]=='$') //Start of sequence
		{
			returnString+='$';

			while(true)
			{
				bytesRead = read(file, readChar, 1);

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
			return "";
		}
	}

	close(file);

	return returnString;
}
