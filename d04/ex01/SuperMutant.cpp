#include "SuperMutant.hpp"

SuperMutant::SuperMutant(void) : Enemy(170, "Super Mutant") {
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
	return ;
}

SuperMutant::SuperMutant(SuperMutant const & copy) : Enemy(copy) {
	*this = copy;
	std::cout << "SuperMutant is copied." << std::endl;
	return ;
}

SuperMutant::~SuperMutant( void ) {
	std::cout << "Aaargh ..." << std::endl;
	return ;
}

SuperMutant & SuperMutant::operator=(SuperMutant const & b) {
	this->setType(b.getType());
	this->setHP(b.getHP());
	return *this;
}

void SuperMutant::takeDamage(int amount) {
	int damage = ((int)(amount - 3) > 0) ? (amount - 3) : 0;
	this->setHP(this->getHP() - damage);
	if (this->getHP() <= 0 )
		this->setHP(0);
}
