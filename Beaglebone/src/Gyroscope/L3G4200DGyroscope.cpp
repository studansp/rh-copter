/*
 * L3G4200DGyroscope.cpp
 *
 *  Created on: May 21, 2014
 *      Author: phillip
 */

#include "L3G4200DGyroscope.h"

L3G4200DGyroscope::L3G4200DGyroscope(std::string namebuf, char address)
	: AbstractI2CDevice(namebuf, address) {
}

L3G4200DGyroscope::~L3G4200DGyroscope() {
}

