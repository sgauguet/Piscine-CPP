#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _zombie_name(name) {
	std::cout << "Zombie " << this->getZombieName() << " is born." << std::endl;
}

Zombie::~Zombie( void ) {
	std::cout << "Zombie " << this->getZombieName() << " is dead." << std::endl;
}

void Zombie::announce(void) const {
	std::cout << getZombieName() << " of type " << getZombieType() << " said Braiiiiiiinnnssss..." << std::endl;
}

std::string Zombie::getZombieName (void) const {
	return this->_zombie_name;
}

void Zombie::setZombieName (std::string name) {
	this->_zombie_name = name;
}

std::string Zombie::getZombieType (void) const {
	return this->_zombie_type;
}

void Zombie::setZombieType (std::string type) {
	this->_zombie_type = type;
}
