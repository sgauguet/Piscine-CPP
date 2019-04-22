#include "FragTrap.hpp"

FragTrap::FragTrap(void) : _name("Bob"), _hit_points(100), _max_hits_points(100), _energy_points(100), _max_energy_points(100), _level(1), _melee_attack(30), _ranged_attack(20), _shout_attack(5), _cyber_attack(35), _mars_attack(55), _armor_damage_reduction(5) {
	std::cout << "FR4G-TP " << this->_name << " is born. (default constructor)" << std::endl;
	return ;
}

FragTrap::FragTrap(std::string name) : _name(name), _hit_points(100), _max_hits_points(100), _energy_points(100), _max_energy_points(100), _level(1), _melee_attack(30), _ranged_attack(20), _shout_attack(5), _cyber_attack(35), _mars_attack(55), _armor_damage_reduction(5) {
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

void	FragTrap::rangedAttack(std::string const & target) {
	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " at range, causing " << this->_ranged_attack << " points of damage !" << std::endl;
}

void	FragTrap::meleeAttack(std::string const & target) {
	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " at melee, causing " << this->_melee_attack << " points of damage !" << std::endl;
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

void	FragTrap::takeDamage(unsigned int amount) {
	int damage = ((int)(amount - this->_armor_damage_reduction) > 0) ? (amount - this->_armor_damage_reduction) : 0;
	this->_hit_points -= damage;
	if (this->_hit_points < 0 )
		this->_hit_points = 0;
	std::cout << "FR4G-TP " << this->_name << " takes " << damage << " points of damage !" << " It has now " << this->_hit_points << " hit points." << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount) {
	this->_hit_points += amount;
	if (this->_hit_points > this-> _max_hits_points)
		this->_hit_points = this-> _max_hits_points;
	std::cout << "FR4G-TP " << this->_name << " is repaired." << " It has now " << (((int)amount > this->_max_hits_points) ? this->_max_hits_points : amount) << " more hit points." << std::endl;
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
	random_number = std::rand() % max_value + min_value;
	(this->*f[random_number])(target);
}
