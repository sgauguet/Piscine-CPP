#ifndef BOCALSTEROID_H
#define BOCALSTEROID_H

#include "IAsteroid.hpp"
#include <iostream>

class BocalSteroid : public IAsteroid {

public:

	BocalSteroid(void);
	BocalSteroid(BocalSteroid const & copy);
	virtual ~BocalSteroid(void);
	BocalSteroid & operator=(BocalSteroid const & b);

	std::string beMined(DeepCoreMiner * laser) const;
	std::string beMined(StripMiner * laser) const;
	std::string getName() const;

private: 
	std::string _name;
};

#endif
