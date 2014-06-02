/*
 * Main.cpp
 *
 *  Created on: May 18, 2014
 *      Author: phillip
 */


#include<iostream>
#include "GPS/SainSmartNEO6MGPS.h"
#include "Accelerometer/ADXL345Accelerometer.h"
#include "Gyroscope/L3G4200DGyroscope.h"
#include "Motor/Turnigy2209Motor.h"
#include "Quadcopter/AbstractQuadcopter.h"
#include "Quadcopter/RHCopter.h"

using namespace std;

int main()
{
	AbstractQuadcopter* copter = new RHCopter();

	copter->Refresh("");

	delete copter;

	/*
	SainSmartNEO6MGPS gps("/dev/i2c-1",0x42);
	gps.Refresh("");

	cout << "Is GPS Valid?: " << gps.IsValid() << endl;

	ADXL345Accelerometer accel("/dev/i2c-1",0x53);
	accel.Refresh("");

	cout << "Is accelerometer Valid?: " << accel.IsValid() << endl;

	cout << "Accel Xg? " << accel.Xg() << endl;
	cout << "Accel Yg? " << accel.Yg() << endl;
	cout << "Accel Zg? " << accel.Zg() << endl;

	L3G4200DGyroscope gyro("/dev/i2c-1",0x69);

	gyro.Refresh("");


	cout << "Is gyroscope Valid? " << gyro.IsValid() << endl;

	cout << "Gyro X? " << gyro.X_dps() << endl;
	cout << "Gyro Y? " << gyro.Y_dps() << endl;
	cout << "Gyro Z? " << gyro.Z_dps() << endl;
	*/
}
