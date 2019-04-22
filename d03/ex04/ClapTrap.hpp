#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>
#include <cstdlib>

class ClapTrap {

public:

	ClapTrap(void);
	ClapTrap(std::string name, int hit_points, int max_hits_points, int energy_points, int max_energy_points, int level, int melee_attack, int ranged_attack, int armor_damage_reduction);
	ClapTrap(ClapTrap const & copy);
	~ClapTrap(void);
	ClapTrap & operator=(ClapTrap const & b);

	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void showAttributes(void) const;

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
