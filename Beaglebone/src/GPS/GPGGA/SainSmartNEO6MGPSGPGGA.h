/*
 * SainSmartNEO6MGPSGPGGA.h
 *
 *  Created on: May 20, 2014
 *      Author: phillip
 */

#ifndef SAINSMARTNEO6MGPSGPGGA_H_
#define SAINSMARTNEO6MGPSGPGGA_H_
#include "GPGGA.h"

class SainSmartNEO6MGPSGPGGA : public GPGGA {
public:
	SainSmartNEO6MGPSGPGGA();
	virtual ~SainSmartNEO6MGPSGPGGA();
	virtual void Refresh(std::string input);
};

#endif /* SAINSMARTNEO6MGPSGPGGA_H_ */
