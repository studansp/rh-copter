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

int16_t ADXL345Accelerometer::X()
{
	return _x;
}

int16_t ADXL345Accelerometer::Y()
{
	return _y;
}

int16_t ADXL345Accelerometer::Z()
{
	return _z;
}

void ADXL345Accelerometer::ReadData()
{
	if(InitRead())
	{
		//WORK IN PROGRESS, NOT FUNCTIONAL

		//Read X
		_x = (Read(0x33)<<8) | Read(0x32);

		//Read Y
		_y = (Read(0x35)<<8) | Read(0x34);

		//Read Z
		_z = (Read(0x37)<<8) | Read(0x36);

		EndRead();
	}
}
