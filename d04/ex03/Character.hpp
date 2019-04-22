#ifndef CHARACTER_H
#define CHARACTER_H

#include "ICharacter.hpp"
#include <iostream>

class Character : public ICharacter {

public:

	Character(void);
	Character(std::string const & name);
	Character(Character const & copy);
	virtual ~Character(void);
	Character & operator=(Character const & b);

	std::string const & getName(void) const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

private:
	std::string _name;
	AMateria* _inventory[4];
};

#endif
