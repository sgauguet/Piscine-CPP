#ifndef ICE_H
#define ICE_H

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{

public:
	Ice(void);
	Ice(Ice const & copy);
	virtual ~Ice(void);
	Ice & operator=(Ice const & );

	AMateria* clone() const;
	void use(ICharacter& target);

};

#endif
