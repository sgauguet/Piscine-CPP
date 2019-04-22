#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int main( void ) {
	std::cout << "----- " << "Instantiation of SuperTrap" << " -----" << std::endl;
	SuperTrap bob = SuperTrap("Bob");
	bob.showAttributes();
	std::cout << "----- " << "Instantiation of FragTrap" << " -----" << std::endl;
	FragTrap max("Max");
	max.showAttributes();
	std::cout << "----- " << "Instantiation of NinjaTrap" << " -----" << std::endl;
	NinjaTrap johnny("Johnny");
	johnny.showAttributes();
	std::cout << "----- " << "Instantiation of ScavTrap" << " -----" << std::endl;
	ScavTrap jane("Jane");
	jane.showAttributes();
	std::cout << "----- " << "Instantiation of ClapTrap" << " -----" << std::endl;
	ClapTrap henry;
	henry.showAttributes();
	std::cout << "----- " << "Test of SuperTrap" << " -----" << std::endl;
	bob.rangedAttack("Rambo");
	bob.meleeAttack("Rambo");
	bob.vaulthunter_dot_exe("Rambo");
	bob.ninjaShoebox(max);
	bob.ninjaShoebox(johnny);
	bob.ninjaShoebox(jane);
	bob.ninjaShoebox(henry);
	bob.takeDamage(15);
	bob.beRepaired(1);
	return 0;
}
