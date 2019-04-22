#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include <iostream>
#include <cstdlib>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

public:

	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const & copy);
	~ScavTrap(void);
	ScavTrap & operator=(ScavTrap const & b);

	void challengeNewcomer(std::string const & target);

private:

	void smallChallenge(std::string const & target);
	void mediumChallenge(std::string const & target);
	void bigChallenge(std::string const & target);

	int _small_challenge;
	int _medium_challenge;
	int _big_challenge;

};

#endif
