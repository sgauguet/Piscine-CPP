#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap(), _small_challenge(2), _medium_challenge(7), _big_challenge(15) {
	std::cout << "ScavTrap " << this->_name << " is born." << std::endl;
	this->_energy_points = 50;
	this->_max_energy_points = 50;
	this->_melee_attack = 20;
	this->_ranged_attack = 15;
	this->_armor_damage_reduction = 3;
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _small_challenge(2), _medium_challenge(7), _big_challenge(15) {
	std::cout << "ScavTrap " << name << " is born." << std::endl;
	this->_energy_points = 50;
	this->_max_energy_points = 50;
	this->_melee_attack = 20;
	this->_ranged_attack = 15;
	this->_armor_damage_reduction = 3;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const & copy) {
	*this = copy;
	std::cout << "ScavTrap " << this->_name << " is copied." << std::endl;
	return ;
}

ScavTrap::~ScavTrap( void ) {
	std::cout << "ScavTrap " << this->_name << " is dead." << std::endl;
	return ;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & b) {
	this->_name = b._name;
	this->_hit_points = b._hit_points;
	this->_max_hits_points = b._max_hits_points;
	this->_energy_points = b._energy_points;
	this->_max_energy_points = b._max_energy_points;
	this->_level = b._level;
	this->_melee_attack = b._melee_attack;
	this->_ranged_attack = b._ranged_attack;
	this->_small_challenge = b._small_challenge;
	this->_medium_challenge = b._medium_challenge;
	this->_big_challenge = b._big_challenge;
	this->_armor_damage_reduction = b._armor_damage_reduction;
	return *this;
}

void	ScavTrap::smallChallenge(std::string const & target) {
	std::cout << "ScavTrap " << this->_name << " challenges " << target << ". This is a small challenge, causing " << this->_small_challenge << " points of damage !" << std::endl;
}

void	ScavTrap::mediumChallenge(std::string const & target) {
	std::cout << "ScavTrap " << this->_name << " challenges " << target << ". This is a medium challenge, causing " << this->_medium_challenge << " points of damage !" << std::endl;
}

void	ScavTrap::bigChallenge(std::string const & target) {
	std::cout << "ScavTrap " << this->_name << " challenges " << target << ". This is a big challenge, causing " << this->_big_challenge << " points of damage !" << std::endl;
}

void	ScavTrap::challengeNewcomer(std::string const & target) {
	int random_number, max_value = 3, min_value = 0;
	void (ScavTrap::*f[3])(std::string const & target);
	if (this->_energy_points - 25 < 0) {
		std::cout << "ScavTrap " << this->_name << " can't challenge new comer." << " It has not enough energy points." << std::endl;
		return ;
	}
	this->_energy_points -= 25;
	f[0] = &ScavTrap::smallChallenge;
	f[1] = &ScavTrap::mediumChallenge;
	f[2] = &ScavTrap::bigChallenge;
	random_number = rand() % max_value + min_value;
	(this->*f[random_number])(target);
}
