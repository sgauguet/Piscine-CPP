#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>
#include <cstdlib>

class ClapTrap {

public:

	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const & copy);
	~ClapTrap(void);
	ClapTrap & operator=(ClapTrap const & b);

	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	std::string getName(void) const;

protected:

	std::string _name;
	int _hit_points;
	int _max_hits_points;
	int _energy_points;
	int _max_energy_points;
	int _level;
	int _melee_attack;
	int _ranged_attack;
	int _armor_damage_reduction;

};

#endif
