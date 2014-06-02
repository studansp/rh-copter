/*
 * AbstractMotor.h
 *
 *  Created on: Jun 2, 2014
 *      Author: phillip
 */

#ifndef ABSTRACTMOTOR_H_
#define ABSTRACTMOTOR_H_

class AbstractMotor {
public:
	AbstractMotor();
	virtual ~AbstractMotor();
	virtual bool SetMotorPercent(int percent)=0;
	virtual int GetMotorPercent()=0;
};

#endif /* ABSTRACTMOTOR_H_ */
