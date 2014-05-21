/*
 * GPGGA.h
 *
 *  Created on: May 20, 2014
 *      Author: phillip
 */

#ifndef GPGGA_H_
#define GPGGA_H_

#include <string>
#include "../../Shared/Validatable.h"
#include "../../Shared/Refreshable.h"
#include "../Navigation/LatLong.h"


class GPGGA : public Validatable, public Refreshable{
public:
	GPGGA();
	virtual ~GPGGA();

protected:
	std::string _utcTime;
	LatLong* _latitude;
	LatLong* _longitude;
	int _fixQuality;
	int _numSatellites;
	float _horizontalDilution;
	float _altitude;
	float _geoidHeight;
	void deleteObjects();
};

#endif /* GPGGA_H_ */
