#ifndef SORCERER_H
#define SORCERER_H

#include <iostream>
#include "Victim.hpp"

class Sorcerer {

public:

	Sorcerer(std::string name, std::string title);
	Sorcerer(Sorcerer const & copy);
	~Sorcerer(void);
	Sorcerer & operator=(Sorcerer const & b);

	std::string getName(void) const;
	std::string getTitle(void) const;
	void polymorph(Victim const & victim) const;

private:

	Sorcerer(void);
	
	std::string _name;
	std::string _title;

};

std::ostream & operator<<(std::ostream & o, Sorcerer const & rhs); // rhs = right-hand-side

#endif
