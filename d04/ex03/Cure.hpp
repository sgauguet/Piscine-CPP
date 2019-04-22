#ifndef CURE_H
#define CURE_H

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{

public:
	Cure(void);
	Cure(Cure const & copy);
	virtual ~Cure(void);
	Cure & operator=(Cure const & );

	AMateria* clone() const;
	void use(ICharacter& target);

};

#endif
