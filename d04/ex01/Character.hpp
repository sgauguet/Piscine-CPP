#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character {

public:

	Character(void);
	Character(std::string const & name);
	Character(Character const & copy);
	~Character(void);
	Character & operator=(Character const & b);

	void recoverAP(void);
	void equip(AWeapon* ptr);
	void attack(Enemy* a);

	std::string getName(void) const;
	int getAP(void) const;
	AWeapon * getWeapon(void) const;
	
private:

	std::string _name;
	int	_AP;
	AWeapon * _ptr;
};

std::ostream & operator<<(std::ostream & o, Character const & rhs);

#endif
