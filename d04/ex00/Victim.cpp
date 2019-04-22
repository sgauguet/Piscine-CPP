#include "Victim.hpp"

Victim::Victim(void) {
	std::cout << "Some random victim called " << this->_name << " just popped ! (default constructor)" << std::endl;
	return ;
}

Victim::Victim(std::string name) : _name(name) {
	std::cout << "Some random victim called " << name << " just popped !" << std::endl;
	return ;
}

Victim::Victim(Victim const & copy) {
	*this = copy;
	std::cout << "Victim " << this->_name << " is copied." << std::endl;
	return ;
}

Victim::~Victim( void ) {
	std::cout << "Victim " << this->_name << " just died for no apparent reason !" << std::endl;
	return ;
}

Victim & Victim::operator=(Victim const & b) {
	this->_name = b._name;
	return *this;
}

std::string Victim::getName(void) const {
	return this->_name;
}

void Victim::getPolymorphed(void) const {
	std::cout << this->_name << " has been turned into a cute little sheep !" << std::endl;
}

std::ostream & operator<<(std::ostream & o, Victim const & rhs) {
	o << "I'm " << rhs.getName() << " and I like otters !" << std::endl;
	return o;
}
