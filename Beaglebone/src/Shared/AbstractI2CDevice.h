/*
 * AbstractI2CDevice.h
 *
 *  Created on: May 20, 2014
 *      Author: phillip
 */

#ifndef ABSTRACTI2CDEVICE_H_
#define ABSTRACTI2CDEVICE_H_
#include <string>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/fcntl.h>
#include <iostream>
#include <stdio.h>
#include <stropts.h>
#include <unistd.h>

class AbstractI2CDevice {
public:
	AbstractI2CDevice(std::string namebuf, char address);
	virtual ~AbstractI2CDevice();
	void EndRead();
	bool InitRead();
	bool Read(void* buf, std::size_t size);
	bool Write(void* buf, std::size_t size);
	bool Write(char reg, char data);
	char Read(char reg);
	int GetTwosCompliment16(int data);
protected:
	std::string _namebuf;
	char _address;
	int _file;
};

#endif /* ABSTRACTI2CDEVICE_H_ */
