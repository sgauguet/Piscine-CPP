#ifndef ZOMBIE_HORDE_H
#define ZOMBIE_HORDE_H

#include <iostream>
#include <string>
#include <cstdlib>
#include "Zombie.hpp"

class ZombieHorde {

public: 

	ZombieHorde(int number);
	~ZombieHorde(void);

	void    	announce(void);

	Zombie 		*getZombieHorde(void);
	void 		setZombieType(Zombie *zombie, std::string type);
	std::string getRandomName(void);

private:

	Zombie *_zombies;
	int		_hord_size;
};
 
#endif
