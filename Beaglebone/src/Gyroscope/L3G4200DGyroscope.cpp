/*
 * L3G4200DGyroscope.cpp
 *
 *  Created on: May 21, 2014
 *      Author: phillip
 */

#include "L3G4200DGyroscope.h"

L3G4200DGyroscope::L3G4200DGyroscope(std::string namebuf, char address)
	: AbstractI2CDevice(namebuf, address) {
	if(InitRead())
	{
		//Enable axes
		Write(0x20, 0x0F);

		//250 dps
		Write(0x23, 0x00);

		EndRead();
	}
}

L3G4200DGyroscope::~L3G4200DGyroscope() {
}

float L3G4200DGyroscope::X_dps()
{
	return ((_x + L3G4200D_X_BIAS)* 8.75) / 1000.0;
}

float L3G4200DGyroscope::Y_dps()
{
	return ((_y + L3G4200D_Y_BIAS) * 8.75) / 1000.0;
}

float L3G4200DGyroscope::Z_dps()
{
	return ((_z + L3G4200D_Z_BIAS) * 8.75) / 1000.0;
}

void L3G4200DGyroscope::ReadData()
{
	if(InitRead())
	{
		char xL=Read(0x28);
		char xH=Read(0x29);
		char yL=Read(0x2A);
		char yH=Read(0x2B);
		char zL=Read(0x2C);
		char zH=Read(0x2D);


		int x = (xH << 8) | xL;
		int y = (yH << 8) | yL;
		int z = (zH << 8) | zL;

		_x = GetTwosCompliment16(x);
		_y = GetTwosCompliment16(y);
		_z = GetTwosCompliment16(z);

		EndRead();
	}

}
