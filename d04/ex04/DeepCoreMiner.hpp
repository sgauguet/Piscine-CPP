#ifndef DEEPCOREMINER_H
#define DEEPCOREMINER_H

#include "IMiningLaser.hpp"
#include <iostream>
class IMiningLaser;

class DeepCoreMiner : public IMiningLaser {

public:

	DeepCoreMiner(void);
	DeepCoreMiner(DeepCoreMiner const & copy);
	virtual ~DeepCoreMiner(void);
	DeepCoreMiner & operator=(DeepCoreMiner const & b);

	void mine(IAsteroid* target);

};

#endif
