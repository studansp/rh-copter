/*
 * Turnigy2209Motor.h
 *
 *  Created on: Jun 2, 2014
 *      Author: phillip
 */

#ifndef TURNIGY2209MOTOR_H_
#define TURNIGY2209MOTOR_H_

#include "AbstractMotor.h"
#include "../Shared/AbstractPWMDevice.h"
#include <string>

#define TURNIGY2209_PWM_LOW 1000000
#define TURNIGY2209_PWM_HIGH 2000000

class Turnigy2209Motor: public AbstractMotor, public AbstractPWMDevice {
public:
	Turnigy2209Motor(std::string folder);
	virtual ~Turnigy2209Motor();
	virtual bool SetMotorPercent(int percent);
	virtual int GetMotorPercent();
};

#endif /* TURNIGY2209MOTOR_H_ */
