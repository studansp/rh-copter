#pragma once

#include <string>
#include "DirectionContainer.h"
#include "LatLong.h"
#include "Variation.h"

class GPRMC
{
public:
	GPRMC(std::string input);
	void Refresh(std::string input);
	bool IsValid();
	~GPRMC();

private:
	std::string _utcTime;
	bool _validity;

	LatLong* _latitude;
	LatLong* _longitude;

	float _speedKnots;
	float _trueCourse;
	std::string _dateStamp;

	Variation* _variation;

	std::string _checksum;
	void deleteObjects();
};
