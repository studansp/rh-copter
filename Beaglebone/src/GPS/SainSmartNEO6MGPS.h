/*
 * SainSmartNEO6MGPS.h
 *
 *  Created on: May 18, 2014
 *      Author: phillip
 */

#ifndef SAINSMARTNEO6MGPS_H_
#define SAINSMARTNEO6MGPS_H_
#include <string>

using namespace std;

class SainSmartNEO6MGPS {
public:
	SainSmartNEO6MGPS(string namebuf, char address);
	std::string GetNextString();
private:
	void openFile();

	string _namebuf;
	char _address;

};

#endif /* SAINSMARTNEO6MGPS_H_ */
