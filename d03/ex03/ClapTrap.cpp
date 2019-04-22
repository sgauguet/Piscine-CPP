#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Bob"), _hit_points(100), _max_hits_points(100), _energy_points(100), _max_energy_points(100), _level(1), _melee_attack(30), _ranged_attack(20), _armor_damage_reduction(5) {
	std::cout << "ClapTrap " << this->_name << " is born." << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(100), _max_hits_points(100), _energy_points(100), _max_energy_points(100), _level(1), _melee_attack(30), _ranged_attack(20), _armor_damage_reduction(5) {
	std::cout << "ClapTrap " << name << " is born." << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const & copy) {
	*this = copy;
	std::cout << "ClapTrap " << this->_name << " is copied." << std::endl;
	return ;
}

ClapTrap::~ClapTrap( void ) {
	std::cout << "ClapTrap " << this->_name << " is dead." << std::endl;
	return ;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & b) {
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

void	ClapTrap::rangedAttack(std::string const & target) {
	std::cout << this->_name << " attacks " << target << " at range, causing " << this->_ranged_attack << " points of damage !" << std::endl;
}

void	ClapTrap::meleeAttack(std::string const & target) {
	std::cout << this->_name << " attacks " << target << " at melee, causing " << this->_melee_attack << " points of damage !" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	int damage = ((int)(amount - this->_armor_damage_reduction) > 0) ? (amount - this->_armor_damage_reduction) : 0;
	this->_hit_points -= damage;
	if (this->_hit_points < 0 )
		this->_hit_points = 0;
	std::cout << this->_name << " takes " << damage << " points of damage !" << " It has now " << this->_hit_points << " hit points." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	this->_hit_points += amount;
	if (this->_hit_points > this-> _max_hits_points)
		this->_hit_points = this-> _max_hits_points;
	std::cout << this->_name << " is repaired." << " It has now " << amount << " more hit points." << std::endl;
}

std::string ClapTrap::getName(void) const {
	return this->_name;
}
