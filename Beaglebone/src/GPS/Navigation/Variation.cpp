#include "Variation.h"
#include <cstdlib>

//Parse variation from input data
//Google NMEA strings for more information
Variation::Variation(std::string degrees, std::string direction)
{
	_degrees = atof(degrees.c_str());
	_direction = new DirectionContainer(direction);
}


Variation::~Variation(void)
{
	delete _direction;
}
