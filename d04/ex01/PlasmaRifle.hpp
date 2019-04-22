#ifndef PLASMARIFLE_H
#define PLASMARIFLE_H

#include <iostream>
#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {

public:

	PlasmaRifle(void);
	PlasmaRifle(PlasmaRifle const & copy);
	~PlasmaRifle(void);
	PlasmaRifle & operator=(PlasmaRifle const & b);

	void attack() const;

};

#endif
