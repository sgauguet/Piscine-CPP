#ifndef ASTEROBOCAL_H
#define ASTEROBOCAL_H

#include "IAsteroid.hpp"
#include <iostream>

class AsteroBocal : public IAsteroid {

public:

	AsteroBocal(void);
	AsteroBocal(AsteroBocal const & copy);
	virtual ~AsteroBocal(void);
	AsteroBocal & operator=(AsteroBocal const & b);

	std::string beMined(DeepCoreMiner * laser) const;
	std::string beMined(StripMiner * laser) const;
	std::string getName() const;

private: 
	std::string _name;
};

#endif
