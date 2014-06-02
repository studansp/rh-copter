/*
 * RHCopter.cpp
 *
 *  Created on: Jun 2, 2014
 *      Author: phillip
 */

#include "RHCopter.h"
#include "../GPS/SainSmartNEO6MGPS.h"
#include "../Accelerometer/ADXL345Accelerometer.h"
#include "../Gyroscope/L3G4200DGyroscope.h"
#include "../Motor/Turnigy2209Motor.h"


RHCopter::RHCopter() {

	SetGPS(new SainSmartNEO6MGPS(I2C_PATH,0x42));
	SetAccelerometer(new ADXL345Accelerometer(I2C_PATH,0x53));
	SetGyroscope(new L3G4200DGyroscope(I2C_PATH,0x69));

	SetMotor(1, new Turnigy2209Motor("/sys/devices/ocp.2/pwm_test_P8_13.10/"));
	SetMotor(2, new Turnigy2209Motor("/sys/devices/ocp.2/pwm_test_P8_13.10/"));
	SetMotor(3, new Turnigy2209Motor("/sys/devices/ocp.2/pwm_test_P8_13.10/"));
	SetMotor(4, new Turnigy2209Motor("/sys/devices/ocp.2/pwm_test_P8_13.10/"));
}

RHCopter::~RHCopter() {
}

