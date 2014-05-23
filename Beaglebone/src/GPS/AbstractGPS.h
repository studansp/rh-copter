/*
 * AbstractGPS.h
 *
 *  Created on: May 19, 2014
 *      Author: phillip
 */

#ifndef ABSTRACTGPS_H_
#define ABSTRACTGPS_H_
#include "GPGGA/GPGGA.h"
#include "../Shared/Refreshable.h"

class AbstractGPS : public Refreshable {
public:
	AbstractGPS();
	virtual ~AbstractGPS();
	bool IsValid();
protected:
	GPGGA* _gpgga;
};

#endif /* ABSTRACTGPS_H_ */
