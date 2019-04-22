#include "SuperTrap.hpp"

SuperTrap::SuperTrap(void) : ClapTrap("Bob", 100, 100, 120, 120, 1, 60, 20, 5) {
	std::cout << "SuperTrap is born." << std::endl;
	return ;
}

SuperTrap::SuperTrap(std::string name) : ClapTrap(name, 100, 100, 120, 120, 1, 60, 20, 5) {
	std::cout << "SuperTrap " << name << " is born." << std::endl;
	return ;
}

SuperTrap::SuperTrap(SuperTrap const & copy) : ClapTrap(copy) {
	*this = copy;
	std::cout << "SuperTrap is copied." << std::endl;
	return ;
}

SuperTrap::~SuperTrap( void ) {
	std::cout << "SuperTrap "  << this->_name << " is dead." << std::endl;
	return ;
}

SuperTrap & SuperTrap::operator=(SuperTrap const & b) {
	ClapTrap::operator=(b);
	return *this;
}

void SuperTrap::rangedAttack(std::string const & target) {
	FragTrap::rangedAttack(target);
}

void SuperTrap::meleeAttack(std::string const & target) {
	NinjaTrap::meleeAttack(target);
}
