#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(void) : AWeapon("Plasma Rifle", 5, 21) {
	//std::cout << "(default constructor)" << std::endl;
	return ;
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const & copy) : AWeapon(copy) {
	*this = copy;
	std::cout << "PlasmaRifle " << this->getName() << " is copied." << std::endl;
	return ;
}

PlasmaRifle::~PlasmaRifle( void ) {
	//std::cout << "PlasmaRifle " << this->getName() << " is destructed !" << std::endl;
	return ;
}

PlasmaRifle & PlasmaRifle::operator=(PlasmaRifle const & b) {
	this->setName(b.getName());
	this->setAPCost(b.getAPCost());
	this->setDamage(b.getDamage());
	return *this;
}

void PlasmaRifle::attack() const {
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
