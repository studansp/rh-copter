/*
 * AbstractGPS.cpp
 *
 *  Created on: May 19, 2014
 *      Author: phillip
 */

#include "AbstractGPS.h"
#include <stdlib.h>

#ifndef NULL
#define NULL ((void *)0)
#endif

AbstractGPS::AbstractGPS() {
	_gprmc = NULL;
	_gpgga = NULL;
}

AbstractGPS::~AbstractGPS() {
	if(_gprmc!=NULL)
	{
		delete _gprmc;
	}
	if(_gpgga!=NULL)
	{
		delete _gpgga;
	}
}

bool AbstractGPS::IsValid()
{
	return (_gprmc!=NULL && _gprmc->IsValid())
			|| (_gpgga!=NULL && _gpgga->IsValid());
}
