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
	virtual float Xg() = 0;
	virtual float Yg() = 0;
	virtual float Zg() = 0;
};

#endif /* ABSTRACTACCELEROMETER_H_ */
