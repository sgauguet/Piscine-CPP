#ifndef NINJATRAP_H
#define NINJATRAP_H

#include <iostream>
#include <cstdlib>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class NinjaTrap : public virtual ClapTrap {

public:

	NinjaTrap(void);
	NinjaTrap(std::string name);
	NinjaTrap(NinjaTrap const & copy);
	~NinjaTrap(void);
	NinjaTrap & operator=(NinjaTrap const & b);

	void ninjaShoebox(NinjaTrap & target);
	void ninjaShoebox(ClapTrap & target);
	void ninjaShoebox(FragTrap & target);
	void ninjaShoebox(ScavTrap & target);

};

#endif
