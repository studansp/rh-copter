/*
 * Refreshable.h
 *
 *  Created on: May 20, 2014
 *      Author: phillip
 */

#ifndef REFRESHABLE_H_
#define REFRESHABLE_H_
#include <string>
#include "Validatable.h"

class Refreshable : public Validatable{
public:
	Refreshable();
	virtual ~Refreshable();
	virtual void Refresh(std::string input)=0;
};

#endif /* REFRESHABLE_H_ */
