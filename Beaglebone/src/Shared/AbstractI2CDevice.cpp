/*
 * AbstractI2CDevice.cpp
 *
 *  Created on: May 20, 2014
 *      Author: phillip
 */

#include "AbstractI2CDevice.h"

//Return two's compliment from raw 16 bit data
int AbstractI2CDevice::GetTwosCompliment16(int data)
{
	if(data & (1 << 15))
		return data | ~65535;
	return data & 65535;
}

//Init default values
AbstractI2CDevice::AbstractI2CDevice(std::string namebuf, char address)
{
	_namebuf = namebuf;
	_address = address;
	_file=0;
}

AbstractI2CDevice::~AbstractI2CDevice() { }

//Read a single character at a register
bool AbstractI2CDevice::Read(char reg, char* inChar)
{
	char wrBuf[1];
	wrBuf[0]=reg;

	write(_file, wrBuf, 1);

	return read(_file, inChar, 1)==1;
}

//Write a single character to a given register
bool AbstractI2CDevice::Write(char reg, char data)
{
	char buf[2];

	buf[0] =reg;
	buf[1] =data;

	return write(_file, buf, 2)==2;
}

//Write a series of characters
bool AbstractI2CDevice::Write(void* buf, int size)
{
	return write(_file, buf, size)==size;
}

//Read a single character
bool AbstractI2CDevice::Read(void* buf, int size)
{
	return read(_file, buf, size)==size;
}

//Called when finished with I2C communication
void AbstractI2CDevice::EndReadWrite()
{
	close(_file);
}

//Called to initiate I2C communication
bool AbstractI2CDevice::InitReadWrite()
{
	if((_file = open(_namebuf.c_str(), O_RDWR)) < 0)
	{
		std::cout << "Failed to open file";
		return false;
	}

	if(ioctl(_file, I2C_SLAVE, _address) < 0)
	{
		std::cout << "Unable to open IO";
		return false;
	}

	return true;
}

