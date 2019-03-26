#include "Pony.hpp"

Pony::Pony(std::string name, std::string type) : _pony_name(name), _pony_type(type) {
	std::cout << "A new pony is born on the " << this->_pony_type << "." << std::endl;
}

Pony::~Pony( void ) {
	std::cout << "Pony " << getPonyName() << " is dead." << std::endl;
}

std::string Pony::getPonyName (void) const {
	return this->_pony_name;
}

void Pony::setPonyName (std::string name) {
	this->_pony_name = name;
}