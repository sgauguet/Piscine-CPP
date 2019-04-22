#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"


int main( void ) {
	FragTrap bob = FragTrap("Bob");
	ScavTrap bib = ScavTrap("Bib");

	bob.takeDamage(15);
	bob.beRepaired(4);
	bob.takeDamage(15);
	bib.takeDamage(155);
	bib.beRepaired(90);
	bib.takeDamage(1);
	bob.vaulthunter_dot_exe("Max");
	bob.vaulthunter_dot_exe("Max");
	bob.vaulthunter_dot_exe("Max");
	bob.vaulthunter_dot_exe("Max");
	bob.vaulthunter_dot_exe("Max");
	bob.vaulthunter_dot_exe("Max");
	bib.challengeNewcomer("Bob");

	return 0;
}
