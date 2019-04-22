#include "Character.hpp"

Character::Character(void) {
	this->_inventory[0] = NULL;
	this->_inventory[1] = NULL;
	this->_inventory[2] = NULL;
	this->_inventory[3] = NULL;
	return ;
}

Character::Character(std::string const & name) : _name(name) {
	this->_inventory[0] = NULL;
	this->_inventory[1] = NULL;
	this->_inventory[2] = NULL;
	this->_inventory[3] = NULL;
	return ;
}

Character::Character(Character const & copy) {
	this->_inventory[0] = copy._inventory[0];
	this->_inventory[1] = copy._inventory[1];
	this->_inventory[2] = copy._inventory[2];
	this->_inventory[3] = copy._inventory[3];
	this->_name = copy._name;
	std::cout << "Character is copied." << std::endl;
	return ;
}

Character::~Character( void ) {
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] != NULL) {
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
	return ;
}

Character & Character::operator=(Character const & b) {
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
		this->_inventory[i] = b._inventory[i];
	}
	this->_name = b._name;
	return *this;
}

std::string const & Character::getName(void) const {
	return this->_name;
}

void Character::equip(AMateria* m) {
	int i;

	i = 0;
	while (i < 4) {
		if (this->_inventory[i] == NULL) {
			this->_inventory[i] = m;
			break;
		}
		i++;
	}
}

void Character::unequip(int idx) {
	if (idx > 3 || idx < 0)
		return;
	if (this->_inventory[idx] != NULL) {
		this->_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx > 3 || idx < 0 || this->_inventory[idx] == NULL)
		return ;
	this->_inventory[idx]->use(target);
}
