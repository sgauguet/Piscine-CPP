#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "NinjaTrap.hpp"


int main( void ) {
	FragTrap bab = FragTrap("Bab");
	ScavTrap bib = ScavTrap("Bib");
	NinjaTrap bub = NinjaTrap("Bub");
	ClapTrap bob;

	bab.takeDamage(15);
	bab.beRepaired(4);
	bab.takeDamage(15);
	bib.takeDamage(155);
	bib.beRepaired(90);
	bib.takeDamage(1);
	bab.vaulthunter_dot_exe("Max");
	bib.challengeNewcomer("Bob");

	bub.ninjaShoebox(bob);
	bub.ninjaShoebox(bib);
	bub.ninjaShoebox(bub);
	bub.ninjaShoebox(bab);

	return 0;
}
