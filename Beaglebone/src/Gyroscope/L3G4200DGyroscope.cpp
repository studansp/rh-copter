/*
 * L3G4200DGyroscope.cpp
 *
 *  Created on: May 21, 2014
 *      Author: phillip
 */

#include "L3G4200DGyroscope.h"

bool L3G4200DGyroscope::SetRange(int range)
{
	//Per datasheet section 7.5
	bool returnValue = true;

	returnValue = Write(L3G4200D_CTRL_REG4, range);

	//Set dps coefficient
	switch(range)
	{
		case L3G4200D_SCALE_250:
			_dpsCoefficient=.00875;  //These numbers per datasheet section 2.1
			break;
		case L3G4200D_SCALE_500:
			_dpsCoefficient=.0175;
			break;
		case L3G4200D_SCALE_2000:
			_dpsCoefficient=.0700;
			break;
		default:
			returnValue=false;
	}

	return returnValue;
}

L3G4200DGyroscope::L3G4200DGyroscope(std::string namebuf, char address)
	: AbstractI2CDevice(namebuf, address) {
	if(InitReadWrite())
	{
		//Enable axes
		if(!Write(L3G4200D_CTRL_REG1, L3G4200D_CTRL_REG1_ALL_AXES))
		{
			FatalError("L3G4200D unable to enable axes during initialization");
		}

		//Set range
		if(!SetRange(L3G4200D_SCALE_250))
		{
			FatalError("L3G4200D unable to set range during initialization");
		}

		//Set data ready
		if(!Write(L3G4200D_CTRL_REG3, 0x08))
		{
			FatalError("L3G4200D unable to set data ready");
		}

		EndReadWrite();
	}
	else
	{
		FatalError("L3G4200D unable to open for read write during initialization");
	}
}

L3G4200DGyroscope::~L3G4200DGyroscope() {
}

float L3G4200DGyroscope::X_dps()
{
	return _x* _dpsCoefficient;
}

float L3G4200DGyroscope::Y_dps()
{
	return _y * _dpsCoefficient;
}

float L3G4200DGyroscope::Z_dps()
{
	return _z * _dpsCoefficient;
}

void L3G4200DGyroscope::Refresh(std::string input)
{
	if(InitReadWrite())
	{
		char buf[6];

		Read(L3G4200D_WHOAMI, &buf[0]);

		//Make sure we haven't lost sync
		if(buf[0]==L3G4200D_WHOAMI_EXPECTED)
		{
			_validity = (
				Read(L3G4200D_XLOW, &buf[0])
				&& Read(L3G4200D_XHIGH, &buf[1])
				&& Read(L3G4200D_YLOW, &buf[2])
				&& Read(L3G4200D_YHIGH, &buf[3])
				&& Read(L3G4200D_ZLOW, &buf[4])
				&& Read(L3G4200D_ZHIGH, &buf[5])
			);

			_x = GetTwosCompliment16(((buf[1] << 8) | buf[0]));
			_y = GetTwosCompliment16(((buf[3] << 8) | buf[2]));
			_z = GetTwosCompliment16(((buf[5] << 8) | buf[4]));
		}
		else
		{
			_validity = false;
		}

		EndReadWrite();
	}

}
