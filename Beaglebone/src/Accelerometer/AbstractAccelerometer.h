/*
 * AbstractAccelerometer.h
 *
 *  Created on: May 21, 2014
 *      Author: phillip
 */

#ifndef ABSTRACTACCELEROMETER_H_
#define ABSTRACTACCELEROMETER_H_
#include "../Shared/Validatable.h"
#include <stdint.h>

class AbstractAccelerometer : public Validatable {
public:
	AbstractAccelerometer();
	virtual ~AbstractAccelerometer();
	virtual void ReadData()=0;
	virtual int16_t X() = 0;
	virtual int16_t Y() = 0;
	virtual int16_t Z() = 0;
};

#endif /* ABSTRACTACCELEROMETER_H_ */
