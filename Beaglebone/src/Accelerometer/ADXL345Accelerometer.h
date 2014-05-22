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

#define ADXL345_BUFFER 0x80

class ADXL345Accelerometer : public AbstractAccelerometer, public AbstractI2CDevice {
public:
	ADXL345Accelerometer(std::string namebuf, char address);
	virtual ~ADXL345Accelerometer();
	virtual void ReadData();
	virtual int16_t X();
	virtual int16_t Y();
	virtual int16_t Z();

private:
	char buffer[ADXL345_BUFFER];
	int16_t _x;
	int16_t _y;
	int16_t _z;
};

#endif /* ADXL345ACCELEROMETER_H_ */
