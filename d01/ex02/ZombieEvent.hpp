#ifndef ZOMBIE_EVENT_H
#define ZOMBIE_EVENT_H

#include <iostream>
#include <string>
#include <cstdlib>
#include "Zombie.hpp"

class ZombieEvent {

public: 

	ZombieEvent(void);
	~ZombieEvent(void);

	Zombie *newZombie(std::string name);
	void setZombieType(Zombie *zombie, std::string type);
	std::string getRandomName(void);
	void randomChump(void);

private:

	std::string _zombie_name;
	std::string _type;

};
 
#endif
