#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include "IMateriaSource.hpp"
#include <iostream>

class MateriaSource : public IMateriaSource {

public:

	MateriaSource(void);
	MateriaSource(std::string const & name, int apcost, int damage);
	MateriaSource(MateriaSource const & copy);
	virtual ~MateriaSource(void);
	MateriaSource & operator=(MateriaSource const & b);

	void learnMateria(AMateria* materia);
	AMateria* createMateria(std::string const & type);

private:
	AMateria* _sources[4];
};

#endif
