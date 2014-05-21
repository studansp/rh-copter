#ifndef GPRMC_H_
#define GPRMC_H_

#include <string>
#include "../Navigation/DirectionContainer.h"
#include "../Navigation/LatLong.h"
#include "../Navigation/Variation.h"
#include "../../Shared/Validatable.h"
#include "../../Shared/Refreshable.h"

class GPRMC : public Validatable, public Refreshable
{
public:
	GPRMC();
	virtual ~GPRMC();

protected:
	std::string _utcTime;

	LatLong* _latitude;
	LatLong* _longitude;

	float _speedKnots;
	float _trueCourse;
	std::string _dateStamp;

	Variation* _variation;

	std::string _checksum;
	void deleteObjects();
};

#endif
