#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(void) : ClapTrap("Ninja", 60, 60, 120, 120, 1, 60, 5, 0) {
	std::cout << "NinjaTrap " << this->_name << " is born." << std::endl;
	return ;
}

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name, 60, 60, 120, 120, 1, 60, 5, 0) {
	std::cout << "NinjaTrap " << name << " is born." << std::endl;
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
	this->_armor_damage_reduction = b._armor_damage_reduction;
	return *this;
}

void	NinjaTrap::ninjaShoebox(NinjaTrap & target) {
	std::cout << this->_name << " says カッコウ忍者 to his friends " << target.getName() << "." << std::endl;
}

void	NinjaTrap::ninjaShoebox(ClapTrap & target) {
	std::cout << this->_name << " tried to kick " << target.getName() << ", but he missed." << std::endl;
}

void	NinjaTrap::ninjaShoebox(FragTrap & target) {
	std::cout << this->_name << " atacks Fragtrap " << target.getName() << " !!!! Pif !" << std::endl;
}

void	NinjaTrap::ninjaShoebox(ScavTrap & target) {
	std::cout << this->_name << " atacks Scavtrap " << target.getName() << " !!!! Pouf !" << std::endl;
}
