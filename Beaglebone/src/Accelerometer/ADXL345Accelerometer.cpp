/*
 * ADXL345Accelerometer.cpp
 *
 *  Created on: May 21, 2014
 *      Author: phillip
 */

#include "ADXL345Accelerometer.h"
#include <iostream>

ADXL345Accelerometer::ADXL345Accelerometer(std::string namebuf, char address)
: AbstractI2CDevice(namebuf, address)
{
	if(InitRead())
	{
		//Put in measure mode
		Write(0x2D, (1<<3));

		//Set range to +- 4G
		Write(0x31, (1<<0));

		EndRead();
	}
}

ADXL345Accelerometer::~ADXL345Accelerometer() {
}


//TODO There is something wrong here
//These values should be much more uniform
float ADXL345Accelerometer::Xg()
{
	return (_x)*0.0078;
}

float ADXL345Accelerometer::Yg()
{
	return (_y)*0.0078;
}

float ADXL345Accelerometer::Zg()
{
	return (_z)*0.0078;
}

void ADXL345Accelerometer::ReadData()
{
	if(InitRead())
	{
		//WORK IN PROGRESS, NOT FUNCTIONAL

		//Read X
		_x = GetTwosCompliment16((Read(0x33)<<8) | Read(0x32));

		//Read Y
		_y = GetTwosCompliment16((Read(0x35)<<8) | Read(0x34));

		//Read Z
		_z = GetTwosCompliment16((Read(0x37)<<8) | Read(0x36));

		EndRead();
	}
}
