#ifndef AMATERIA_H
#define AMATERIA_H

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {

public:
	AMateria(void) ;
	AMateria(std::string const & type);
	AMateria(AMateria const & copy);
	virtual ~AMateria(void);
	AMateria & operator=(AMateria const & b);

	std::string const & getType() const; //Returns the materia type
	unsigned int getXP() const; //Returns the Materia!s XP
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

private:
	std::string _type;
	unsigned int _xp;
};

#endif
