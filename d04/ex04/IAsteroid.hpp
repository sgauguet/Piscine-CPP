#ifndef IASTEROID_H
#define IASTEROID_H

#include <iostream>
class DeepCoreMiner;
class StripMiner;

class IAsteroid
{
public:
	virtual ~IAsteroid() {}
	virtual std::string beMined(DeepCoreMiner * laser) const = 0;
	virtual std::string beMined(StripMiner * laser) const = 0;
	virtual std::string getName() const = 0;
};

#endif
