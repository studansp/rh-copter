#ifndef LATLONG_H_
#define LATLONG_H_

#include "DirectionContainer.h"
#include <string>

class LatLong
{
public:
	LatLong(std::string data, std::string direction);
	~LatLong();
private:
	int _degree;
	float _min;
	DirectionContainer* _direction;
};

#endif
