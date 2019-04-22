#include "AMateria.hpp"

AMateria::AMateria(void) {
	return ;
}

AMateria::AMateria(std::string const & type) : _type(type), _xp(0) {
	return ;
}

AMateria::AMateria(AMateria const & copy) {
	*this = copy;
	return ;
}

AMateria::~AMateria(void) {
	return ;
}

AMateria & AMateria::operator=(AMateria const & b) {
	this->_xp = b._xp;
	return *this;
}

std::string const & AMateria::getType(void) const {
	return this->_type;
}

unsigned int AMateria::getXP(void) const {
	return this->_xp;
}

void AMateria::use(ICharacter& target) {
	if (&target)
		this->_xp += 10;
	return;
}
