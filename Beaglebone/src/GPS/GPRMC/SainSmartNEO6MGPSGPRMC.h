/*
 * SainSmartNEO6MGPSGPRMC.h
 *
 *  Created on: May 20, 2014
 *      Author: phillip
 */

#ifndef SAINSMARTNEO6MGPSGPRMC_H_
#define SAINSMARTNEO6MGPSGPRMC_H_

#include "GPRMC.h"

class SainSmartNEO6MGPSGPRMC: public GPRMC {
public:
	SainSmartNEO6MGPSGPRMC();
	virtual ~SainSmartNEO6MGPSGPRMC();
	virtual void Refresh(std::string input);
};

#endif /* SAINSMARTNEO6MGPSGPRMC_H_ */
