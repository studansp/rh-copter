/*
 * AbstractPWMDevice.cpp
 *
 *  Created on: Jun 2, 2014
 *      Author: phillip
 */

#include "AbstractPWMDevice.h"
#include <cstdlib>

AbstractPWMDevice::AbstractPWMDevice(std::string folder, int low, int high) {
	_folder = folder;
	_low = low;
	_high = high;

	SetDutyPercent(0);
	SetPeriod(DEFAULT_PERIOD);
	SetPolarity(DEFAULT_POLARITY);
}

AbstractPWMDevice::~AbstractPWMDevice() {
}

int AbstractPWMDevice::GetDutyPercent()
{
	return getPercentForValue(_duty);
}

bool AbstractPWMDevice::SetDutyPercent(int percent)
{
	if(percent<0 || percent>100)
		return false;

	_duty = getValueForPercent(percent);

	std::string writeString("echo ");
	writeString += _duty;
	writeString += " > ";
	writeString += _folder;
	writeString += "/duty";

	system(writeString.c_str());
	return true;

	return true;
}

int AbstractPWMDevice::getPercentForValue(int value)
{
	if(value<_low || value>_high)
		return 0;

	return ( (value-_low) / (float(_high-_low)) )*100.0;

}

int AbstractPWMDevice::getValueForPercent(int percent)
{
	if(percent<0 || percent>100)
		return 0;

	return (_low + (_high-_low) * (percent / 100.0));
}

bool AbstractPWMDevice::SetPeriod(int period)
{
	_period = period;

	std::string writeString("echo ");
	writeString += period;
	writeString += " > ";
	writeString += _folder;
	writeString += "/period";

	system(writeString.c_str());
	return true;
}

bool AbstractPWMDevice::SetPolarity(int polarity)
{
	_polarity = polarity;

	std::string writeString("echo ");
	writeString += polarity;
	writeString += " > ";
	writeString += _folder;
	writeString += "/polarity";

	system(writeString.c_str());
	return true;
}
