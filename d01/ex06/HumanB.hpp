#ifndef HUMAN_B_H
#define HUMAN_B_H

#include <iostream>
#include "Weapon.hpp"

class HumanB {

public: 

	HumanB(std::string name);
	~HumanB(void);

	void	attack(void) const;
	void	setWeapon(Weapon& club);
	
private:

	std::string	_name;
	Weapon* 	_weapon;
};
 
#endif
