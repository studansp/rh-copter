/*
 * AbstractGyroscope.h
 *
 *  Created on: May 21, 2014
 *      Author: phillip
 */

#ifndef ABSTRACTGYROSCOPE_H_
#define ABSTRACTGYROSCOPE_H_
#include "../Shared/Validatable.h"

class AbstractGyroscope : public Validatable{
public:
	AbstractGyroscope();
	virtual ~AbstractGyroscope();
	virtual void ReadData()=0;
	virtual float X_dps()=0;
	virtual float Y_dps()=0;
	virtual float Z_dps()=0;
};

#endif /* ABSTRACTGYROSCOPE_H_ */
