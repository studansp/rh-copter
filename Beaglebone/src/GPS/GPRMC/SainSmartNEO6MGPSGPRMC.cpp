/*
 * SainSmartNEO6MGPSGPRMC.cpp
 *
 *  Created on: May 20, 2014
 *      Author: phillip
 */

#include "SainSmartNEO6MGPSGPRMC.h"
#include <vector>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/predicate.hpp>

SainSmartNEO6MGPSGPRMC::SainSmartNEO6MGPSGPRMC() {
}

SainSmartNEO6MGPSGPRMC::~SainSmartNEO6MGPSGPRMC() {
}

void SainSmartNEO6MGPSGPRMC::Refresh(std::string input)
{
	std::vector<std::string> strs;

	boost::split(strs, input, boost::is_any_of(",*"));

	if(strs[0]!="$GPRMC" || strs.size()!=14 )
	{
		std::cerr << "Invalid $GPRMC string: " << input << " Length:" << strs.size();
		this->_validity = false;
	}
	else
	{
		if(strs[2]=="A") //Valid
		{
			this->_validity = true;

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
			this->_validity = false;
		}
	}
}
