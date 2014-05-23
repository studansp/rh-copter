/*
 * ADXL345Accelerometer.h
 *
 *  Created on: May 21, 2014
 *      Author: phillip
 */

#ifndef ADXL345ACCELEROMETER_H_
#define ADXL345ACCELEROMETER_H_

#include <stdint.h>
#include "AbstractAccelerometer.h"
#include "../Shared/AbstractI2CDevice.h"

//Define a bunch of stuff from the datasheet
#define ADXL345_POWER_CTL 0X2D
#define ADXL345_DATA_FORMAT 0x31
#define ADXL345_DATA_FORMAT_2G 0
#define ADXL345_DATA_FORMAT_4G 1
#define ADXL345_DATA_FORMAT_8G 2
#define ADXL345_DATA_FORMAT_16G 3

//Data for each axis

#define ADXL345_XLOW 0x32
#define ADXL345_XHIGH 0x33
#define ADXL345_YLOW 0x34
#define ADXL345_YHIGH 0x35
#define ADXL345_ZLOW 0x36
#define ADXL345_ZHIGH 0x37

#define ADXL345_MAX_G_VALUE 1024


class ADXL345Accelerometer : public AbstractAccelerometer, public AbstractI2CDevice {
public:
	ADXL345Accelerometer(std::string namebuf, char address);
	virtual ~ADXL345Accelerometer();
	virtual void Refresh(std::string input);
	virtual float Xg();
	virtual float Yg();
	virtual float Zg();

private:
	int16_t _x;
	int16_t _y;
	int16_t _z;
	float _gCoefficient;
	bool SetGRange(int range);
};

#endif /* ADXL345ACCELEROMETER_H_ */
