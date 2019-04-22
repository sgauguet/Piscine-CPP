#include "Sorcerer.hpp"

Sorcerer::Sorcerer(void) {
	std::cout << "(default constructor)" << std::endl;
	return ;
}

Sorcerer::Sorcerer(std::string name, std::string title) : _name(name), _title(title) {
	std::cout << name << ", " << title << ", is born !" << std::endl;
	return ;
}

Sorcerer::Sorcerer(Sorcerer const & copy) {
	*this = copy;
	std::cout << "Sorcerer " << this->_name << " is copied." << std::endl;
	return ;
}

Sorcerer::~Sorcerer( void ) {
	std::cout << this->_name << ", " << this->_title << ", is dead. Consequences will never be the same !" << std::endl;
	return ;
}

Sorcerer & Sorcerer::operator=(Sorcerer const & b) {
	this->_name = b._name;
	this->_title = b._title;
	return *this;
}

std::string Sorcerer::getName(void) const {
	return this->_name;
}

std::string Sorcerer::getTitle(void) const {
	return this->_title;
}

void Sorcerer::polymorph(Victim const & victim) const {
	victim.getPolymorphed();
}

std::ostream & operator<<(std::ostream & o, Sorcerer const & rhs) {
	o << "I am " << rhs.getName() << ", " << rhs.getTitle() << ", and I like ponies !" << std::endl;
	return o;
}

