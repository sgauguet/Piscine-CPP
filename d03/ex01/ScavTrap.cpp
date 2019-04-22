#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : _name("Bob"), _hit_points(100), _max_hits_points(100), _energy_points(50), _max_energy_points(50), _level(1), _melee_attack(20), _ranged_attack(15), _armor_damage_reduction(3) {
	std::cout << "ScavTrap " << this->_name << " is constructed." << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name) : _name(name), _hit_points(100), _max_hits_points(100), _energy_points(50), _max_energy_points(50), _level(1), _melee_attack(20), _ranged_attack(15), _armor_damage_reduction(3) {
	std::cout << "ScavTrap " << name << " is constructed." << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const & copy) {
	*this = copy;
	std::cout << "ScavTrap " << this->_name << " is copied." << std::endl;
	return ;
}

ScavTrap::~ScavTrap( void ) {
	std::cout << "ScavTrap " << this->_name << " is destructed." << std::endl;
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
	this->_armor_damage_reduction = b._armor_damage_reduction;
	return *this;
}

void	ScavTrap::rangedAttack(std::string const & target) {
	std::cout << "ScavTrap " << this->_name << " attacks " << target << " at range, causing " << this->_ranged_attack << " points of damage !" << std::endl;
}

void	ScavTrap::meleeAttack(std::string const & target) {
	std::cout << "ScavTrap " << this->_name << " attacks " << target << " at melee, causing " << this->_melee_attack << " points of damage !" << std::endl;
}

void	ScavTrap::smallChallenge(std::string const & target) {
	std::cout << "ScavTrap " << this->_name << " challenges " << target << ". Small challenge : eat a teaspoon of wasabi." << std::endl;
}

void	ScavTrap::mediumChallenge(std::string const & target) {
	std::cout << "ScavTrap " << this->_name << " challenges " << target << ". Medium challenge : eat an entire hot pepper." << std::endl;
}

void	ScavTrap::bigChallenge(std::string const & target) {
	std::cout << "ScavTrap " << this->_name << " challenges " << target << ". Big challenge : eat your own computer." << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount) {
	int damage = ((int)(amount - this->_armor_damage_reduction) > 0) ? (amount - this->_armor_damage_reduction) : 0;
	this->_hit_points -= damage;
	if (this->_hit_points < 0 )
		this->_hit_points = 0;
	std::cout << "ScavTrap " << this->_name << " takes " << damage << " points of damage !" << " It has now " << this->_hit_points << " hit points." << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount) {
	this->_hit_points += amount;
	if (this->_hit_points > this-> _max_hits_points)
		this->_hit_points = this-> _max_hits_points;
	std::cout << "ScavTrap " << this->_name << " is repaired." << " It has now " << (((int)amount > this->_max_hits_points) ? this->_max_hits_points : amount) << " more hit points." << std::endl;
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
