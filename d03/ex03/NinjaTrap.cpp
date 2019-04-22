#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(void) : ClapTrap(), _small_challenge(2), _medium_challenge(7), _big_challenge(15) {
	std::cout << "NinjaTrap " << this->_name << " is born." << std::endl;
	this->_hit_points = 60;
	this->_max_hits_points = 60;
	this->_energy_points = 120;
	this->_max_energy_points = 120;
	this->_melee_attack = 60;
	this->_ranged_attack = 5;
	this->_armor_damage_reduction = 0;
	return ;
}

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name), _small_challenge(2), _medium_challenge(7), _big_challenge(15) {
	std::cout << "NinjaTrap " << name << " is born." << std::endl;
	this->_hit_points = 60;
	this->_max_hits_points = 60;
	this->_energy_points = 120;
	this->_max_energy_points = 120;
	this->_melee_attack = 60;
	this->_ranged_attack = 5;
	this->_armor_damage_reduction = 0;
	return ;
}

NinjaTrap::NinjaTrap(NinjaTrap const & copy) {
	*this = copy;
	std::cout << "NinjaTrap " << this->_name << " is copied." << std::endl;
	return ;
}

NinjaTrap::~NinjaTrap( void ) {
	std::cout << "NinjaTrap " << this->_name << " is dead." << std::endl;
	return ;
}

NinjaTrap & NinjaTrap::operator=(NinjaTrap const & b) {
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


void	NinjaTrap::ninjaShoebox(NinjaTrap & target) {
	std::cout << "Ninja says カッコウ忍者 to his friends " << target.getName() << "." << std::endl;
}

void	NinjaTrap::ninjaShoebox(ClapTrap & target) {
	std::cout << "Ninja tried to kick " << target.getName() << ", but he missed." << std::endl;
}

void	NinjaTrap::ninjaShoebox(FragTrap & target) {
	std::cout << "Ninja atacks Fragtrap " << target.getName() << " !!!! Pif !" << std::endl;
}

void	NinjaTrap::ninjaShoebox(ScavTrap & target) {
	std::cout << "Ninja atacks Scavtrap " << target.getName() << " !!!! Pouf !" << std::endl;
}
