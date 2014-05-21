/*
 * Main.cpp
 *
 *  Created on: May 18, 2014
 *      Author: phillip
 */


#include<iostream>
#include "GPS/SainSmartNEO6MGPS.h"
using namespace std;

int main()
{
	SainSmartNEO6MGPS gps("/dev/i2c-1",0x42);
	gps.ReadData();

	cout << "Is Valid?: " << gps.IsValid() << endl;

	return 0;
}
