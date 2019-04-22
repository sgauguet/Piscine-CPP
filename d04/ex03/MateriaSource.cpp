#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
	this->_sources[0] = NULL;
	this->_sources[1] = NULL;
	this->_sources[2] = NULL;
	this->_sources[3] = NULL;
	return ;
}

MateriaSource::MateriaSource(MateriaSource const & copy) {
	this->_sources[0] = copy._sources[0];
	this->_sources[1] = copy._sources[1];
	this->_sources[2] = copy._sources[2];
	this->_sources[3] = copy._sources[3];
	std::cout << "MateriaSource is copied." << std::endl;
	return ;
}

MateriaSource::~MateriaSource( void ) {
	for (int i = 0; i < 4; i++) {
		if (this->_sources[i] != NULL)
			delete this->_sources[i];
	}
	return ;
}

MateriaSource & MateriaSource::operator=(MateriaSource const & b) {
	for (int i = 0; i < 4; i++) {
		if (this->_sources[i] != NULL)
			delete this->_sources[i];
		this->_sources[i] = b._sources[i];
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* materia) {
	int i;

	i = 0;
	while (i < 4) {
		if (this->_sources[i] == NULL) {
			this->_sources[i] = materia;
			break;
		}
		i++;
	}
	return;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (this->_sources[i] != NULL && this->_sources[i]->getType() == type) {
			return this->_sources[i]->clone();
		}
	}
	return 0;
}
