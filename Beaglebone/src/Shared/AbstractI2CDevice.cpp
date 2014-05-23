/*
 * AbstractI2CDevice.cpp
 *
 *  Created on: May 20, 2014
 *      Author: phillip
 */

#include "AbstractI2CDevice.h"

int AbstractI2CDevice::GetTwosCompliment16(int data)
{
	if(data & (1 << 15))
		return data | ~65535;
	return data & 65535;
}

AbstractI2CDevice::AbstractI2CDevice(std::string namebuf, char address)
{
	_namebuf = namebuf;
	_address = address;
}

AbstractI2CDevice::~AbstractI2CDevice() {
}

char AbstractI2CDevice::Read(char reg)
{
	char wrBuf[1];
	wrBuf[0]=reg;

	write(_file, wrBuf, 1);

	char buf[1];

	read(_file, buf, 1);

	return buf[0];
}

bool AbstractI2CDevice::Write(char reg, char data)
{
	char buf[2];

	buf[0] =reg;
	buf[1] =data;

	return write(_file, buf, 2)==2;
}

bool AbstractI2CDevice::Write(void* buf, std::size_t size)
{
	return write(_file, buf, size)!=-1;
}

bool AbstractI2CDevice::Read(void* buf, std::size_t size)
{
	return read(_file, buf, size)!=-1;
}

void AbstractI2CDevice::EndRead()
{
	close(_file);
}

bool AbstractI2CDevice::InitRead()
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

