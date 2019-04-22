#include "Peon.hpp"

Peon::Peon(void) {
	std::cout << "(default constructor)" << std::endl;
	return ;
}

Peon::Peon(std::string name) : Victim(name) {
	this->_name = name;
	std::cout << "Zog zog." << std::endl;
	return ;
}

Peon::Peon(Peon const & copy) : Victim(copy) {
	*this = copy;
	std::cout << "Peon " << this->_name << " is copied." << std::endl;
	return ;
}

Peon::~Peon( void ) {
	std::cout << "Bleuark..." << std::endl;
	return ;
}

Peon & Peon::operator=(Peon const & b) {
	this->_name = b._name;
	return *this;
}

void Peon::getPolymorphed(void) const {
	std::cout << this->_name << " has been turned into a pink pony !" << std::endl;
}

std::ostream & operator<<(std::ostream & o, Peon const & rhs) {
	o << "I'm " << rhs.getName() << " and I like otters !" << std::endl;
	return o;
}
