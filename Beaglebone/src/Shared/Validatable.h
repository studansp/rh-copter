/*
 * Validatable.h
 *
 *  Created on: May 20, 2014
 *      Author: phillip
 */

#ifndef VALIDATABLE_H_
#define VALIDATABLE_H_

class Validatable {
public:
	Validatable();
	virtual ~Validatable();
	virtual bool IsValid();
protected:
	bool _validity;
};

#endif /* VALIDATABLE_H_ */
