/*
 * L3G4200DGyroscope.h
 *
 *  Created on: May 21, 2014
 *      Author: phillip
 */

#ifndef L3G4200DGYROSCOPE_H_
#define L3G4200DGYROSCOPE_H_

#include "AbstractGyroscope.h"
#include "../Shared/AbstractI2CDevice.h"

class L3G4200DGyroscope : public AbstractGyroscope, public AbstractI2CDevice{
public:
	L3G4200DGyroscope(std::string namebuf, char address);
	virtual ~L3G4200DGyroscope();
};

#endif /* L3G4200DGYROSCOPE_H_ */
