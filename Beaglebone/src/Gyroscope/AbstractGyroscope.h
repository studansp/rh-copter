/*
 * AbstractGyroscope.h
 *
 *  Created on: May 21, 2014
 *      Author: phillip
 */

#ifndef ABSTRACTGYROSCOPE_H_
#define ABSTRACTGYROSCOPE_H_
#include "../Shared/Refreshable.h"

class AbstractGyroscope : public Refreshable{
public:
	AbstractGyroscope();
	virtual ~AbstractGyroscope();
	virtual float X_dps()=0;
	virtual float Y_dps()=0;
	virtual float Z_dps()=0;
};

#endif /* ABSTRACTGYROSCOPE_H_ */
