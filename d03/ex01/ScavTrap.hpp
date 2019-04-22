#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include <iostream>
#include <cstdlib>

class ScavTrap {

public:

	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const & copy);
	~ScavTrap(void);
	ScavTrap & operator=(ScavTrap const & b);

	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void challengeNewcomer(std::string const & target);

private:

	void smallChallenge(std::string const & target);
	void mediumChallenge(std::string const & target);
	void bigChallenge(std::string const & target);

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
