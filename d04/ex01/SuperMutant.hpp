#ifndef SUPERMUTANT_H
#define SUPERMUTANT_H

#include "Enemy.hpp"

#include <iostream>

class SuperMutant : public Enemy {

public:

	SuperMutant(void);
	SuperMutant(SuperMutant const & copy);
	~SuperMutant(void);
	SuperMutant & operator=(SuperMutant const & b);

	void takeDamage(int);

};

#endif
