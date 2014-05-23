/*
 * L3G4200DGyroscope.h
 *
 *  Created on: May 21, 2014
 *      Author: phillip
 */

#ifndef L3G4200DGYROSCOPE_H_
#define L3G4200DGYROSCOPE_H_

#define L3G4200D_X_BIAS -140
#define L3G4200D_Y_BIAS -124
#define L3G4200D_Z_BIAS -54

#include "AbstractGyroscope.h"
#include "../Shared/AbstractI2CDevice.h"

class L3G4200DGyroscope : public AbstractGyroscope, public AbstractI2CDevice{
public:
	L3G4200DGyroscope(std::string namebuf, char address);
	virtual ~L3G4200DGyroscope();
	virtual void ReadData();
	virtual float X_dps();
	virtual float Y_dps();
	virtual float Z_dps();

private:
	int _x;
	int _y;
	int _z;
};

#endif /* L3G4200DGYROSCOPE_H_ */
