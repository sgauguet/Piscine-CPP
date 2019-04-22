#ifndef STRIPMINER_H
#define STRIPMINER_H

#include "IMiningLaser.hpp"
#include <iostream>
class IMiningLaser;

class StripMiner : public IMiningLaser {

public:
	StripMiner(void);
	StripMiner(StripMiner const & copy);
	virtual ~StripMiner(void);
	StripMiner & operator=(StripMiner const & b);

	void mine(IAsteroid* target);

};

#endif
