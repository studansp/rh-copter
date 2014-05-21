#include "LatLong.h"
#include <vector>
#include <boost/algorithm/string.hpp>

LatLong::LatLong(std::string data, std::string direction)
{
	_direction = new DirectionContainer(direction);

	std::vector<std::string> strs;

	boost::split(strs, data, boost::is_any_of("."));

	if(strs.size()!=2 || strs[0].length() < 4 || strs[0].length() > 5)
	{
		std::cerr << "Error parsing latitude/longitude data";
	}
	else
	{
		if(strs[0].length()==4)
		{
			_degree = atoi(strs[0].substr(0,2).c_str());
			_min = atof((strs[0].substr(2,2) + "." + strs[1]).c_str());
		}
		else
		{
			_degree = atoi(strs[0].substr(0,3).c_str());
			_min = atof((strs[0].substr(3,2) + "." + strs[1]).c_str());
		}
	}
}

LatLong::~LatLong()
{
	delete _direction;
}
