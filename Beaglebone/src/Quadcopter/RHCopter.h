/*
 * RHCopter.h
 *
 *  Created on: Jun 2, 2014
 *      Author: phillip
 */

#ifndef RHCOPTER_H_
#define RHCOPTER_H_

#include "AbstractQuadcopter.h"

#define I2C_PATH "/dev/i2c-1"

class RHCopter: public AbstractQuadcopter {
public:
	RHCopter();
	virtual ~RHCopter();
};

#endif /* RHCOPTER_H_ */
