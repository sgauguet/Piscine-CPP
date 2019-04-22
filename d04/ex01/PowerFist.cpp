#include "PowerFist.hpp"

PowerFist::PowerFist(void) : AWeapon("Power Fist", 8, 50) {
	//std::cout << "(default constructor)" << std::endl;
	return ;
}

PowerFist::PowerFist(PowerFist const & copy) : AWeapon(copy) {
	*this = copy;
	std::cout << "PowerFist " << this->getName() << " is copied." << std::endl;
	return ;
}

PowerFist::~PowerFist( void ) {
	//std::cout << "PowerFist " << this->getName() << " is destructed !" << std::endl;
	return ;
}

PowerFist & PowerFist::operator=(PowerFist const & b) {
	this->setName(b.getName());
	this->setAPCost(b.getAPCost());
	this->setDamage(b.getDamage());
	return *this;
}

void PowerFist::attack() const {
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
