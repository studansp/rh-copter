#include "Variation.h"
#include <cstdlib>

Variation::Variation(std::string degrees, std::string direction)
{
	_degrees = atof(degrees.c_str());
	_direction = new DirectionContainer(direction);
}


Variation::~Variation(void)
{
	delete _direction;
}
