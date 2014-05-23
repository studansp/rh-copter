/*
 * L3G4200DGyroscope.h
 *
 *  Created on: May 21, 2014
 *      Author: phillip
 */

#ifndef L3G4200DGYROSCOPE_H_
#define L3G4200DGYROSCOPE_H_

#define L3G4200D_CTRL_REG1 0x20

#define L3G4200D_CTRL_REG1_ALL_AXES 0x0F

#define L3G4200D_CTRL_REG2 0x21
#define L3G4200D_CTRL_REG3 0x22
#define L3G4200D_CTRL_REG4 0x23
#define L3G4200D_CTRL_REG5 0x24

#define L3G4200D_SCALE_250 0x00
#define L3G4200D_SCALE_500 0x10
#define L3G4200D_SCALE_2000 0x20

#define L3G4200D_XLOW 0x28
#define L3G4200D_XHIGH 0x29
#define L3G4200D_YLOW 0x2A
#define L3G4200D_YHIGH 0x2B
#define L3G4200D_ZLOW 0x2C
#define L3G4200D_ZHIGH 0x2D

#define L3G4200D_WHOAMI 0x0F
#define L3G4200D_WHOAMI_EXPECTED 0xD3

#include "AbstractGyroscope.h"
#include "../Shared/AbstractI2CDevice.h"

class L3G4200DGyroscope : public AbstractGyroscope, public AbstractI2CDevice{
public:
	L3G4200DGyroscope(std::string namebuf, char address);
	virtual ~L3G4200DGyroscope();
	virtual void Refresh(std::string input);
	virtual float X_dps();
	virtual float Y_dps();
	virtual float Z_dps();
private:
	int _x;
	int _y;
	int _z;
	float _dpsCoefficient;
	bool SetRange(int range);
};

#endif /* L3G4200DGYROSCOPE_H_ */
