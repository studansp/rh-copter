/*
 * Quadcopter.h
 *
 *  Created on: Jun 2, 2014
 *      Author: phillip
 */

#ifndef QUADCOPTER_H_
#define QUADCOPTER_H_

#include "../GPS/AbstractGPS.h"
#include "../Accelerometer/AbstractAccelerometer.h"
#include "../Gyroscope/AbstractGyroscope.h"
#include "../Motor/AbstractMotor.h"
#include "../Shared/Validatable.h"

class AbstractQuadcopter : public Refreshable {
public:
	virtual ~AbstractQuadcopter();

protected:
	AbstractQuadcopter();
	void SetGPS(AbstractGPS* gps);
	void SetAccelerometer(AbstractAccelerometer* accelerometer);
	void SetGyroscope(AbstractGyroscope* gyroscope);
	void SetMotor(int which, AbstractMotor* motor);
	virtual void Refresh(std::string);
private:
	AbstractGPS* _gps;
	AbstractAccelerometer* _accelerometer;
	AbstractGyroscope* _gyroscope;

	AbstractMotor* _motor1;
	AbstractMotor* _motor2;
	AbstractMotor* _motor3;
	AbstractMotor* _motor4;
};

#endif /* QUADCOPTER_H_ */
