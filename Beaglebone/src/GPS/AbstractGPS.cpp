/*
 * AbstractGPS.cpp
 *
 *  Created on: May 19, 2014
 *      Author: phillip
 */

#include "AbstractGPS.h"
#include <stdlib.h>

AbstractGPS::AbstractGPS() {
	_gprmc = NULL;
}

AbstractGPS::~AbstractGPS() {
	if(_gprmc!=NULL)
	{
		delete _gprmc;
	}
}

bool AbstractGPS::IsValid()
{
	if(_gprmc==NULL)
		return false;

	return _gprmc->IsValid();
}
