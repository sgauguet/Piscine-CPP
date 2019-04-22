#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap(), _shout_attack(5), _cyber_attack(35), _mars_attack(55) {
	std::cout << "FR4G-TP " << this->_name << " is born." << std::endl;
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name), _shout_attack(5), _cyber_attack(35), _mars_attack(55) {
	std::cout << "FR4G-TP " << name << " is born." << std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const & copy) {
	*this = copy;
	std::cout << "FR4G-TP " << this->_name << " is copied." << std::endl;
	return ;
}

FragTrap::~FragTrap( void ) {
	std::cout << "FR4G-TP " << this->_name << " is dead." << std::endl;
	return ;
}

FragTrap & FragTrap::operator=(FragTrap const & b) {
	this->_name = b._name;
	this->_hit_points = b._hit_points;
	this->_max_hits_points = b._max_hits_points;
	this->_energy_points = b._energy_points;
	this->_max_energy_points = b._max_energy_points;
	this->_level = b._level;
	this->_melee_attack = b._melee_attack;
	this->_ranged_attack = b._ranged_attack;
	this->_shout_attack = b._shout_attack;
	this->_cyber_attack = b._cyber_attack;
	this->_mars_attack = b._mars_attack;
	this->_armor_damage_reduction = b._armor_damage_reduction;
	return *this;
}

void	FragTrap::intimidatingShout(std::string const & target) {
	std::cout << "FR4G-TP " << this->_name << " raised an intimidating shout ; " << target << " has suffered " << this->_shout_attack << " points of damage !" << std::endl;
}

void	FragTrap::cyberAttack(std::string const & target) {
	std::cout << "FR4G-TP " << this->_name << " launches cyber attack on " << target << ", causing " << this->_cyber_attack << " points of damage !" << std::endl;
}

void	FragTrap::marsAttack(std::string const & target) {
	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " from Mars, causing " << this->_mars_attack << " points of damage !" << std::endl;
}

void	FragTrap::vaulthunter_dot_exe(std::string const & target) {
	int random_number, max_value = 5, min_value = 0;
	void (FragTrap::*f[5])(std::string const & target);
	if (this->_energy_points - 25 < 0) {
		std::cout << "FR4G-TP " << this->_name << " attack failed." << " It has not enough energy points." << std::endl;
		return ;
	}
	this->_energy_points -= 25;
	f[0] = &FragTrap::meleeAttack;
	f[1] = &FragTrap::rangedAttack;
	f[2] = &FragTrap::intimidatingShout;
	f[3] = &FragTrap::cyberAttack;
	f[4] = &FragTrap::marsAttack;
	random_number = rand() % max_value + min_value;
	(this->*f[random_number])(target);
}
