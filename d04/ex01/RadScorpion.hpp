#ifndef RADSCORPION_H
#define RADSCORPION_H

#include "Enemy.hpp"

#include <iostream>

class RadScorpion : public Enemy {

public:

	RadScorpion(void);
	RadScorpion(RadScorpion const & copy);
	~RadScorpion(void);
	RadScorpion & operator=(RadScorpion const & b);

};

#endif
