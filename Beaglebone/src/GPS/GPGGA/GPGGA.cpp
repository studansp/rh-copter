/*
 * GPGGA.cpp
 *
 *  Created on: May 20, 2014
 *      Author: phillip
 */

#include "GPGGA.h"
#include <cstdlib>

GPGGA::GPGGA() {
	_validity = false;
	_latitude = NULL;
	_latitude = NULL;
}

GPGGA::~GPGGA() {
	this->deleteObjects();
}

void GPGGA::deleteObjects()
{
	if(_latitude!=NULL)
		delete(_latitude);
	if(_longitude!=NULL)
		delete(_longitude);
}
