#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include <iostream>
#include <cstdlib>

class FragTrap {

public:

	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(FragTrap const & copy);
	~FragTrap(void);
	FragTrap & operator=(FragTrap const & b);

	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void vaulthunter_dot_exe(std::string const & target);

private:

	void intimidatingShout(std::string const & target);
	void cyberAttack(std::string const & target);
	void marsAttack(std::string const & target);

	std::string _name;
	int _hit_points;
	int _max_hits_points;
	int _energy_points;
	int _max_energy_points;
	int _level;
	int _melee_attack;
	int _ranged_attack;
	int _shout_attack;
	int _cyber_attack;
	int _mars_attack;
	int _armor_damage_reduction;

};

#endif
