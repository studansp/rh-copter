#include "GPRMC.h"
#include <boost/algorithm/string.hpp>
#include <vector>
#include <cstdlib>

void GPRMC::Refresh(std::string input)
{
	std::vector<std::string> strs;

	boost::split(strs, input, boost::is_any_of(",*"));

	if(strs[0]!="$GPRMC" || strs.size()!=14 )
	{
		std::cerr << "Invalid $GPRMC string: " << input << " Length:" << strs.size();
		_validity = false;
	}
	else
	{
		if(strs[2]=="A") //Valid
		{
			_validity = true;

			this->deleteObjects();

			_utcTime=strs[1];
			_latitude=new LatLong(strs[3],strs[4]);
			_longitude=new LatLong(strs[5],strs[6]);
			_speedKnots=atof(strs[7].c_str());
			_trueCourse=atof(strs[8].c_str());
			_dateStamp=strs[9];
			_variation=new Variation(strs[10],strs[11]);
			_checksum=strs[12];
		}
		else
		{
			_validity = false;
		}
	}
}

GPRMC::GPRMC(std::string input)
{
	_latitude=NULL;
	_longitude=NULL;
	_variation=NULL;
	Refresh(input);
}

GPRMC::~GPRMC()
{
	this->deleteObjects();
}

void GPRMC::deleteObjects()
{
	if(_latitude!=NULL)
		delete(_latitude);
	if(_longitude!=NULL)
		delete(_longitude);
	if(_variation!=NULL)
		delete(_variation);
}

bool GPRMC::IsValid()
{
	return _validity;
}
