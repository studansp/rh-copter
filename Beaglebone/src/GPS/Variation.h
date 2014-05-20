#pragma once
#include "DirectionContainer.h"
#include <string>

class Variation
{
public:
	Variation(std::string degrees, std::string direction);
	~Variation(void);

private:
	float _degrees;
	DirectionContainer* _direction;
};
