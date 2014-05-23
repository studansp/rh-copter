#include "GPRMC.h"
#include <boost/algorithm/string.hpp>
#include <vector>
#include <cstdlib>

//Init members
GPRMC::GPRMC()
{
	_latitude=NULL;
	_longitude=NULL;
	_variation=NULL;
	_validity = false;
}

GPRMC::~GPRMC()
{
	this->deleteObjects();
}

//Cleans up pointers
void GPRMC::deleteObjects()
{
	if(_latitude!=NULL)
		delete(_latitude);
	if(_longitude!=NULL)
		delete(_longitude);
	if(_variation!=NULL)
		delete(_variation);
}
