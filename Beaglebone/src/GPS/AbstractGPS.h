/*
 * AbstractGPS.h
 *
 *  Created on: May 19, 2014
 *      Author: phillip
 */

#ifndef ABSTRACTGPS_H_
#define ABSTRACTGPS_H_
#include "GPRMC/GPRMC.h"
#include "GPGGA/GPGGA.h"

class AbstractGPS {
public:
	AbstractGPS();
	virtual ~AbstractGPS();
	virtual void ReadData()=0;
	bool IsValid();
protected:
	GPRMC* _gprmc;
	GPGGA* _gpgga;
};

#endif /* ABSTRACTGPS_H_ */
