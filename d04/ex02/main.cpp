#include "Squad.hpp"
#include "AssaultTerminator.hpp"
#include "ISpaceMarine.hpp"
#include "ISquad.hpp"
#include "TacticalMarine.hpp"

int main( void ) {
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;
	ISquad* vlc = new Squad;
	vlc->push(bob);
	vlc->push(jim);
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	delete vlc;
	std::cout << "----- Tests - Push NULL in Squad -----" << std::endl;
	Squad vlc2;
	vlc2.push(bob);
	std::cout << "The number of units in the Squad is : " << vlc2.getCount() << std::endl;
	vlc2.push(NULL);
	std::cout << "The number of units in the Squad is still : " << vlc2.getCount() << std::endl;
	std::cout << "----- Tests - Push a unit that already exists in Squad -----" << std::endl;
	vlc2.push(bob);
	vlc2.push(bob);
	vlc2.push(bob);
	vlc2.push(bob);
	vlc2.push(bob);
	vlc2.push(bob);
	std::cout << "The number of units in the Squad is still : " << vlc2.getCount() << std::endl;
	std::cout << "----- Tests - Copy constructor -----" << std::endl;
	Squad vlc3;
	vlc3.push(jim);
	vlc3.push(bob);
	for (int i = 0; i < vlc3.getCount(); ++i)
	{
		ISpaceMarine* cur = vlc3.getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	Squad vlc4(vlc3);
	std::cout << "The number of units in the Squad is : " << vlc4.getCount() << std::endl;
	for (int i = 0; i < vlc4.getCount(); ++i)
	{
		ISpaceMarine* cur = vlc4.getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	std::cout << "----- Tests - Assignation operator -----" << std::endl;
	std::cout << "The number of units in the Squad is : " << vlc2.getCount() << std::endl;
	vlc2 = vlc4;
	std::cout << "The number of units in the Squad is : " << vlc2.getCount() << std::endl;
	for (int i = 0; i < vlc2.getCount(); ++i)
	{
		ISpaceMarine* cur = vlc2.getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	delete bob;
	delete jim;
	return 0;
}
