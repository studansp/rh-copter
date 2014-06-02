/*
 * AbstractPWMDevice.h
 *
 *  Created on: Jun 2, 2014
 *      Author: phillip
 */

#ifndef ABSTRACTPWMDEVICE_H_
#define ABSTRACTPWMDEVICE_H_

#include <string>

#define DEFAULT_PERIOD 20000000
#define DEFAULT_POLARITY 0

class AbstractPWMDevice {
public:
	AbstractPWMDevice(std::string folder, int low, int high);
	virtual ~AbstractPWMDevice();
	bool SetDutyPercent(int percent);
	int GetDutyPercent();
	bool SetPeriod(int period);
	bool SetPolarity(int polarity);
private:
	int _low;
	int _high;
	int _period;
	int _duty;
	int _polarity;
	std::string _folder;
	int getPercentForValue(int value);
	int getValueForPercent(int percent);
};

#endif /* ABSTRACTPWMDEVICE_H_ */
