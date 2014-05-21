/*
 * SainSmartNEO6MGPS.h
 *
 *  Created on: May 18, 2014
 *      Author: phillip
 */

#ifndef SAINSMARTNEO6MGPS_H_
#define SAINSMARTNEO6MGPS_H_
#include <string>
#include "AbstractGPS.h"
#include "../Shared/AbstractI2CDevice.h"

class SainSmartNEO6MGPS : public AbstractGPS, public AbstractI2CDevice {
public:
	SainSmartNEO6MGPS(std::string namebuf, char address);
	virtual ~SainSmartNEO6MGPS();
	virtual void ReadData();


private:
	void openFile();
	std::string getNextString();
};

#endif
