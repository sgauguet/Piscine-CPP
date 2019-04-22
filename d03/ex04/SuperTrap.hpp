#ifndef SUPERTRAP_H
#define SUPERTRAP_H

#include <iostream>
#include <cstdlib>
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap {

public:

	SuperTrap(void);
	SuperTrap(std::string name);
	SuperTrap(SuperTrap const & copy);
	~SuperTrap(void);
	SuperTrap & operator=(SuperTrap const & b);

	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
};

#endif
