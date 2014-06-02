/*
 * Quadcopter.cpp
 *
 *  Created on: Jun 2, 2014
 *      Author: phillip
 */

#include "AbstractQuadcopter.h"

void AbstractQuadcopter::Refresh(std::string)
{
	_gps->Refresh("");
	_accelerometer->Refresh("");
	_gyroscope->Refresh("");
}

void AbstractQuadcopter::SetGPS(AbstractGPS* gps)
{
	_gps = gps;
}
void AbstractQuadcopter::SetAccelerometer(AbstractAccelerometer* accelerometer)
{
	_accelerometer = accelerometer;
}

void AbstractQuadcopter::SetGyroscope(AbstractGyroscope* gyroscope)
{
	_gyroscope = gyroscope;
}

void AbstractQuadcopter::SetMotor(int which, AbstractMotor* motor)
{
	if(which==1)
	{
		_motor1 = motor;
	}
	else if(which==2)
	{
		_motor2 = motor;
	}
	else if(which==3)
	{
		_motor3 = motor;
	}
	else if(which==4)
	{
		_motor4 = motor;
	}
	else
	{
		FatalError("Unable to set motor " + which);
	}
}


AbstractQuadcopter::AbstractQuadcopter() {
	// TODO Auto-generated constructor stub

}

AbstractQuadcopter::~AbstractQuadcopter() {
	delete _gps;
	delete _accelerometer;
	delete _gyroscope;

	delete _motor1;
	delete _motor2;
	delete _motor3;
	delete _motor4;
}

