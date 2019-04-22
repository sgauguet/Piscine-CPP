#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {
	return ;
}

Cure::Cure(Cure const & copy) : AMateria(copy) {
	return ;
}

Cure::~Cure( void ) {
	return ;
}

Cure & Cure::operator=(Cure const & b) {
	AMateria::operator=(b);
	return *this;
}

AMateria * Cure::clone(void) const {
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	AMateria::use(target);
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
