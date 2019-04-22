#ifndef POWERFIST_H
#define POWERFIST_H

#include <iostream>
#include "AWeapon.hpp"

class PowerFist :public AWeapon {

public:

	PowerFist(void);
	PowerFist(PowerFist const & copy);
	~PowerFist(void);
	PowerFist & operator=(PowerFist const & b);

	void attack() const;

};

#endif
