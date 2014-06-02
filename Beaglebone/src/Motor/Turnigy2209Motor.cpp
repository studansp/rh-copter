/*
 * Turnigy2209Motor.cpp
 *
 *  Created on: Jun 2, 2014
 *      Author: phillip
 */

#include "Turnigy2209Motor.h"

Turnigy2209Motor::Turnigy2209Motor(std::string folder) : AbstractPWMDevice(folder, TURNIGY2209_PWM_LOW, TURNIGY2209_PWM_HIGH){
}

Turnigy2209Motor::~Turnigy2209Motor() {
}

int Turnigy2209Motor::GetMotorPercent()
{
	return GetDutyPercent();
}

bool Turnigy2209Motor::SetMotorPercent(int percent)
{
	//Set PWM
	return SetDutyPercent(percent);
}
