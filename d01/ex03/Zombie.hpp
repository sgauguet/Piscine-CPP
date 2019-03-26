#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie {

public: 

	Zombie(void);
	~Zombie(void);

	void announce(void) const;

	//Getters and setters
	std::string getZombieName (void) const;
	std::string getZombieType (void) const;
	void setZombieName (std::string name);
	void setZombieType (std::string type);

private:

	std::string _zombie_name;
	std::string _zombie_type;

};
 
#endif