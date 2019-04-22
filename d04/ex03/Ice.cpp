#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {
	return ;
}

Ice::Ice(Ice const & copy) : AMateria(copy) {
	return ;
}

Ice::~Ice( void ) {
	return ;
}

Ice & Ice::operator=(Ice const & b) {
	AMateria::operator=(b);
	return *this;
}

AMateria * Ice::clone(void) const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	AMateria::use(target);
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
