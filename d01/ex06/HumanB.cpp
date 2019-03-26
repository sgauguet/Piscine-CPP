#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {
	return ;
}

HumanB::~HumanB( void ) {
	return ;
}


void HumanB::attack(void) const {
	std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& club) {
	this->_weapon = &club;
}