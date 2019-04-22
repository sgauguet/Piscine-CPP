#include "RadScorpion.hpp"

RadScorpion::RadScorpion(void) : Enemy(80, "RadScorpion") {
	std::cout << "* click click click *" << std::endl;
	return ;
}

RadScorpion::RadScorpion(RadScorpion const & copy) : Enemy(copy) {
	*this = copy;
	std::cout << "RadScorpion is copied." << std::endl;
	return ;
}

RadScorpion::~RadScorpion(void) {
	std::cout << "* SPROTCH *" << std::endl;
	return ;
}

RadScorpion & RadScorpion::operator=(RadScorpion const & b) {
	this->setType(b.getType());
	this->setHP(b.getHP());
	return *this;
}
