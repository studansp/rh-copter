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

using namespace std;

SainSmartNEO6MGPS::SainSmartNEO6MGPS(string namebuf, char address)
{
	_namebuf = namebuf;
	_address = address;
}

std::string SainSmartNEO6MGPS::GetNextString()
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
