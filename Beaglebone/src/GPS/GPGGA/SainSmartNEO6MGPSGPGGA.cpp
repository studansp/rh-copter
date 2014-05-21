/*
 * SainSmartNEO6MGPSGPGGA.cpp
 *
 *  Created on: May 20, 2014
 *      Author: phillip
 */

#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include "SainSmartNEO6MGPSGPGGA.h"
#include "../Navigation/LatLong.h"
#include <vector>

void SainSmartNEO6MGPSGPGGA::Refresh(std::string input)
{
	std::vector<std::string> strs;

	boost::split(strs, input, boost::is_any_of(","));

	if(strs[0]!="$GPGGA" || strs.size()!=15 )
	{
		std::cerr << "Invalid $GPGGA string: " << input << " Length:" << strs.size();
		this->_validity = false;
	}
	else
	{
		if(strs[6]=="1") //Valid
		{
			this->_validity = true;

			_utcTime = strs[1];
			_latitude = new LatLong(strs[2], strs[3]);
			_longitude = new LatLong(strs[4], strs[5]);
			_fixQuality = atoi(strs[6].c_str());
			_numSatellites = atoi(strs[7].c_str());
			_horizontalDilution = atof(strs[8].c_str());
			_altitude = atof(strs[9].c_str());
			_geoidHeight = atof(strs[11].c_str());

			this->deleteObjects();
		}
		else	//Invalid
		{
			this->_validity = false;
		}
	}
}

SainSmartNEO6MGPSGPGGA::SainSmartNEO6MGPSGPGGA() {
}

SainSmartNEO6MGPSGPGGA::~SainSmartNEO6MGPSGPGGA() {}

