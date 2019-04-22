#ifndef IMININGLASER_H
#define IMININGLASER_H

class IAsteroid;
#include <iostream>
#include "IAsteroid.hpp"

class IMiningLaser
{
public:
	virtual ~IMiningLaser() {}
	virtual void mine(IAsteroid*) = 0;
};

#endif
