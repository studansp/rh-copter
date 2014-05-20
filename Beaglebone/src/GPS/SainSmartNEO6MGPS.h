/*
 * SainSmartNEO6MGPS.h
 *
 *  Created on: May 18, 2014
 *      Author: phillip
 */

#ifndef SAINSMARTNEO6MGPS_H_
#define SAINSMARTNEO6MGPS_H_
#include <string>
#include "GPRMC.h"
#include "AbstractGPS.h"

class SainSmartNEO6MGPS : public AbstractGPS {
public:
	SainSmartNEO6MGPS(std::string namebuf, char address);
	~SainSmartNEO6MGPS();
	virtual void ReadData();


private:
	void openFile();
	std::string getNextString();
	std::string _namebuf;
	char _address;
};

#endif
