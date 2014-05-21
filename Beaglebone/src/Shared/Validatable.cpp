/*
 * Validatable.cpp
 *
 *  Created on: May 20, 2014
 *      Author: phillip
 */

#include "Validatable.h"

Validatable::Validatable() {
}

Validatable::~Validatable() {
}

bool Validatable::IsValid()
{
	return _validity;
}
