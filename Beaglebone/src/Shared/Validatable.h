/*
 * Validatable.h
 *
 *  Created on: May 20, 2014
 *      Author: phillip
 */

#ifndef VALIDATABLE_H_
#define VALIDATABLE_H_
#include <string>
#include <iostream>

class Validatable {
public:
	Validatable();
	virtual ~Validatable();
	virtual bool IsValid();
	void FatalError(std::string error);
protected:
	bool _validity;
	bool _notFatalErrored;
};

#endif /* VALIDATABLE_H_ */
