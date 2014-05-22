/*
 * AbstractI2CDevice.cpp
 *
 *  Created on: May 20, 2014
 *      Author: phillip
 */

#include "AbstractI2CDevice.h"
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/fcntl.h>
#include <iostream>
#include <stdio.h>
#include <stropts.h>
#include <unistd.h>

AbstractI2CDevice::AbstractI2CDevice(std::string namebuf, char address)
{
	_namebuf = namebuf;
	_address = address;
}

AbstractI2CDevice::~AbstractI2CDevice() {
}

char AbstractI2CDevice::Read(char reg)
{
	char buf[2];

	buf[0] =reg;

	read(_file, buf, 2);

	return buf[1];
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

