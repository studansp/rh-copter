/*
 * Main.cpp
 *
 *  Created on: May 18, 2014
 *      Author: phillip
 */


#include<iostream>
#include "GPS/SainSmartNEO6MGPS.h"
#include "Accelerometer/ADXL345Accelerometer.h"

using namespace std;

int main()
{
	SainSmartNEO6MGPS gps("/dev/i2c-1",0x42);
	gps.ReadData();

	cout << "Is GPS Valid?: " << gps.IsValid() << endl;

	ADXL345Accelerometer accel("/dev/i2c-1",0x53);
	accel.ReadData();

	cout << "Is accelerometer Valid?: " << accel.IsValid() << endl;

	cout << "Accel X? " << accel.X() << endl;
	cout << "Accel Y? " << accel.Y() << endl;
	cout << "Accel Z? " << accel.Z() << endl;


	return 0;
}
