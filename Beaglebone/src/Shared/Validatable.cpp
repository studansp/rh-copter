/*
 * Validatable.cpp
 *
 *  Created on: May 20, 2014
 *      Author: phillip
 */

#include "Validatable.h"

Validatable::Validatable() {
	_validity = false;
}

Validatable::~Validatable() {
}

bool Validatable::IsValid()
{
	return _validity;
}
