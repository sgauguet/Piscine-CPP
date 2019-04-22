#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Henry"), _hit_points(100), _max_hits_points(100), _energy_points(100), _max_energy_points(100), _level(1), _melee_attack(30), _ranged_attack(20), _armor_damage_reduction(5) {
	std::cout << "ClapTrap " << this->_name << " is born." << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name, int hit_points, int max_hits_points, int energy_points, int max_energy_points, int level, int melee_attack, int ranged_attack, int armor_damage_reduction) : _name(name), _hit_points(hit_points), _max_hits_points(max_hits_points), _energy_points(energy_points), _max_energy_points(max_energy_points), _level(level), _melee_attack(melee_attack), _ranged_attack(ranged_attack), _armor_damage_reduction(armor_damage_reduction) {
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

void	ClapTrap::showAttributes(void) const {
	std::cout << "----- Atributes of Object -----" << std::endl;
	std::cout << "name : " << this->_name << std::endl;
	std::cout << "hit_points : " << this->_hit_points << std::endl;
	std::cout << "max_hits_points : " << this->_max_hits_points << std::endl;
	std::cout << "energy_points : " << this->_energy_points << std::endl;
	std::cout << "max_energy_points : " << this->_max_energy_points << std::endl;
	std::cout << "level : " << this->_level << std::endl;
	std::cout << "melee_attack : " << this->_melee_attack << std::endl;
	std::cout << "ranged_attack : " << this->_ranged_attack << std::endl;
	std::cout << "armor_damage_reduction : " << this->_armor_damage_reduction << std::endl;
}
