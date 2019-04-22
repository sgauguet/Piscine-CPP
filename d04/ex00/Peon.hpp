#ifndef PEON_H
#define PEON_H

#include <iostream>
#include "Victim.hpp"

class Peon : public Victim {

public:

	Peon(std::string name);
	Peon(Peon const & copy);
	virtual ~Peon(void);
	Peon & operator=(Peon const & b);
	void getPolymorphed(void) const;

private:
	Peon(void);
};

std::ostream & operator<<(std::ostream & o, Peon const & rhs); // rhs = right-hand-side

#endif
