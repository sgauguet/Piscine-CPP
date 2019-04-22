#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include <iostream>
#include <cstdlib>
#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap {

public:

	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(FragTrap const & copy);
	~FragTrap(void);
	FragTrap & operator=(FragTrap const & b);

	void vaulthunter_dot_exe(std::string const & target);
	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);

private:
	
	void intimidatingShout(std::string const & target);
	void cyberAttack(std::string const & target);
	void marsAttack(std::string const & target);

	int _shout_attack;
	int _cyber_attack;
	int _mars_attack;

};

#endif
