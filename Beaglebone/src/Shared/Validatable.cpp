/*
 * Validatable.cpp
 *
 *  Created on: May 20, 2014
 *      Author: phillip
 */

#include "Validatable.h"

void Validatable::FatalError(std::string error)
{
	_notFatalErrored = false;

	std::cerr << "Validatable Fatal Error: " << error << std::endl;
}

Validatable::Validatable() {
	_validity = false;
	_notFatalErrored = true;
}

Validatable::~Validatable() {
}

bool Validatable::IsValid()
{
	return _notFatalErrored && _validity;
}
