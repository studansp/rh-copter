#include "DirectionContainer.h"
#include <stdio.h>
#include <stdlib.h>

DirectionContainer::DirectionContainer(std::string input)
{
	if(input.length()==0)
	{
		_direction = DEFAULT;
	}
	else
	{
		char lowerChar = tolower(input[0]);

		switch(lowerChar)
		{
			case 'n':
				_direction = NORTH;
				break;
			case 's':
				_direction = SOUTH;
				break;
			case 'e':
				_direction = EAST;
				break;
			case 'w':
				_direction = WEST;
				break;
			default:
				_direction = DEFAULT;
		}
	}
}


DirectionContainer::~DirectionContainer(void)
{
}


Direction DirectionContainer::GetDirection()
{
	return _direction;
}
