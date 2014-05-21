#ifndef DIRECTIONCONTAINER_H_
#define DIRECTIONCONTAINER_H_

#include <string>
#include "Direction.h"

class DirectionContainer
{
public:
	DirectionContainer(std::string input);
	~DirectionContainer(void);
	Direction GetDirection();
private:
	Direction _direction;
};

#endif
