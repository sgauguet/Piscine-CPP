#include "FragTrap.hpp"

int main( void ) {
	FragTrap a = FragTrap("A");
	FragTrap b;
	FragTrap c(b);
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
	c.takeDamage(1); 
	return 0;
}
