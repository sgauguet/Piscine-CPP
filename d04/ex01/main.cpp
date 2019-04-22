#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "Enemy.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "Character.hpp"

int main( void ) {
	Character* zaz = new Character("zaz");
	std::cout << *zaz;
	Enemy* b = new RadScorpion();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->equip(pf);
	zaz->attack(b);
	std::cout << *zaz;
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	std::cout << "----- Tests - copy constructor - -----" << std::endl;
	SuperMutant c;
	zaz->attack(&c);
	SuperMutant d(c);
	std::cout << "c type : " << c.getType() << std::endl;
	std::cout << "c hp : " << c.getHP() << std::endl;
	std::cout << "d type : " << d.getType() << std::endl;
	std::cout << "d hp : " << d.getHP() << std::endl;
	std::cout << "----- Tests - assignation operator - -----" << std::endl;
	zaz->attack(&c);
	d = c;
	std::cout << "d type : " << d.getType() << std::endl;
	std::cout << "d hp : " << d.getHP() << std::endl;
	std::cout << "----- Tests - attack with no arms - -----" << std::endl;
	Character *e = new Character("Rambo");
	Enemy	*f = new SuperMutant();
	Enemy	*g = new RadScorpion();
	e->attack(f);
	std::cout << *e;
	std::cout << "----- Tests - kill SuperMutant - -----" << std::endl;
	e->equip(pf);
	std::cout << "SuperMutant f has : " << f->getHP() << " hp." << std::endl;
	e->attack(f);
	std::cout << "SuperMutant f has : " << f->getHP() << " hp." << std::endl;
	std::cout << *e;
	e->attack(f);
	std::cout << "SuperMutant f has : " << f->getHP() << " hp." << std::endl;
	std::cout << *e;
	e->attack(f);
	std::cout << "SuperMutant f has : " << f->getHP() << " hp." << std::endl;
	std::cout << *e;
	e->attack(f);
	std::cout << "----- Tests - Attack a dead SuperMutant - -----" << std::endl;
	e->attack(f);
	std::cout << *e;
	std::cout << "----- Tests - Not enough AP to attack twice - -----" << std::endl;
	e->attack(g);
	std::cout << *e;
	e->attack(g);
	std::cout << *e;
	std::cout << "----- Tests - Recover AP to attack - -----" << std::endl;
	e->recoverAP();
	e->attack(g);
	std::cout << *e;
	return 0;
}
