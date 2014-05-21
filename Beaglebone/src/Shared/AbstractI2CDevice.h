/*
 * AbstractI2CDevice.h
 *
 *  Created on: May 20, 2014
 *      Author: phillip
 */

#ifndef ABSTRACTI2CDEVICE_H_
#define ABSTRACTI2CDEVICE_H_
#include <string>

class AbstractI2CDevice {
public:
	AbstractI2CDevice(std::string namebuf, char address);
	virtual ~AbstractI2CDevice();
	void EndRead();
	bool InitRead();
	bool Read(void* buf, std::size_t size);
	bool Write(void* buf, std::size_t size);
protected:
	std::string _namebuf;
	char _address;
	int _file;
};

#endif /* ABSTRACTI2CDEVICE_H_ */
