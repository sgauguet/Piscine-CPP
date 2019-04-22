#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main( void ) {
	FragTrap a = FragTrap("A");
	FragTrap b;
	FragTrap c(b);
	ScavTrap d("Johnny");
	ScavTrap e;
	ScavTrap f(e);

	a.rangedAttack("B");
	a.meleeAttack("B");
	a.takeDamage(15); 
	a.beRepaired(4);
	a.takeDamage(155);
	a.beRepaired(15);
	a.takeDamage(3);
	a.beRepaired(54267);
	a.takeDamage(35);
	a.vaulthunter_dot_exe("C");
	b = a;
	b.vaulthunter_dot_exe("D");
	b.vaulthunter_dot_exe("E");
	b.vaulthunter_dot_exe("F");
	b.vaulthunter_dot_exe("G");

	d.rangedAttack("B");
	d.meleeAttack("B");
	d.takeDamage(15); 
	d.beRepaired(4);
	d.takeDamage(155);
	d.beRepaired(15);
	d.takeDamage(3);
	d.beRepaired(54267);
	d.takeDamage(35);
	d.challengeNewcomer("Rambo");
	e.challengeNewcomer("Rambo");
	f.challengeNewcomer("Rambo");
	f.challengeNewcomer("Rambo");
	return 0;
}
