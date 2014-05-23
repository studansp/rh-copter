/*
 * ADXL345Accelerometer.cpp
 * Accelerometer implementation for ADXL345
 *  Created on: May 21, 2014
 *      Author: phillip
 */

#include "ADXL345Accelerometer.h"
#include <iostream>

//Initialize accelerometer
ADXL345Accelerometer::ADXL345Accelerometer(std::string namebuf, char address)
: AbstractI2CDevice(namebuf, address)
{
	if(InitReadWrite())
	{
		//Per datasheet page 13/25
		//This will put the machine in measurement mode

		if(!Write(ADXL345_POWER_CTL, (1<<3)))
			FatalError("ADXL345 unable to set measurement mode during initialization");

		//Set range
		if(!SetGRange(ADXL345_DATA_FORMAT_4G))
			FatalError("ADXL345 unable to set range during initialization");

		EndReadWrite();
	}
	else
	{
		FatalError("ADXL345 unable to open read/write during initialization");
	}
}

ADXL345Accelerometer::~ADXL345Accelerometer() {
}

//Sets the desired G range
bool ADXL345Accelerometer::SetGRange(int range)
{
	//Per datasheet page 27
	//Set range to selected range
	bool returnValue = true;

	returnValue = Write(ADXL345_DATA_FORMAT, range);

	//Calculate G coefficient
	switch(range)
	{
		case ADXL345_DATA_FORMAT_2G:
			_gCoefficient=4.0/ADXL345_MAX_G_VALUE;
			break;
		case ADXL345_DATA_FORMAT_4G:
			_gCoefficient=8.0/ADXL345_MAX_G_VALUE;
			break;
		case ADXL345_DATA_FORMAT_8G:
			_gCoefficient=16.0/ADXL345_MAX_G_VALUE;
			break;
		case ADXL345_DATA_FORMAT_16G:
			_gCoefficient=32.0/ADXL345_MAX_G_VALUE;
			break;
		default:
			returnValue=false;
	}

	return returnValue;
}

//Returns X component in Gs
float ADXL345Accelerometer::Xg()
{
	return (_x)*_gCoefficient;
}

//Returns Y component in Gs
float ADXL345Accelerometer::Yg()
{
	return (_y)*_gCoefficient;
}

//Returns Z component in Gs
float ADXL345Accelerometer::Zg()
{
	return (_z)*_gCoefficient;
}

//Refreshes state, reads values from input
void ADXL345Accelerometer::Refresh(std::string input)
{
	if(InitReadWrite())
	{

		char buf[6];

		//TODO Data seems a bit funny
		//At rest, Z is only like .8 (expected 1 due to gravity)
		//However, the total is near 1g, so it may be due to how the sensor is sitting

		_validity = (
			Read(ADXL345_XLOW, &buf[0])
			&& Read(ADXL345_XHIGH, &buf[1])
			&& Read(ADXL345_YLOW, &buf[2])
			&& Read(ADXL345_YHIGH, &buf[3])
			&& Read(ADXL345_ZLOW, &buf[4])
			&& Read(ADXL345_ZHIGH, &buf[5])
		);

		_x = GetTwosCompliment16(((buf[1] << 8) | buf[0]));
		_y = GetTwosCompliment16(((buf[3] << 8) | buf[2]));
		_z = GetTwosCompliment16(((buf[5] << 8) | buf[4]));

		EndReadWrite();
	}
	else
	{
		_validity = false;
	}
}
