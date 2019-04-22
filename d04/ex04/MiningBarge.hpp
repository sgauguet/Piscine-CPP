#ifndef MININGBARGE_H
#define MININGBARGE_H

#include <iostream>
#include "IMiningLaser.hpp"

class MiningBarge {

public:

	MiningBarge(void);
	MiningBarge(std::string const & name, int apcost, int damage);
	MiningBarge(MiningBarge const & copy);
	virtual ~MiningBarge(void);
	MiningBarge & operator=(MiningBarge const & b);

	void equip(IMiningLaser* laser);
	void mine(IAsteroid* target) const;

private:
	IMiningLaser* _lasers[4];
};

#endif
