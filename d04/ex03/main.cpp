#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main( void ) {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* zaz = new Character("zaz");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	zaz->equip(tmp);
	tmp = src->createMateria("cure");
	zaz->equip(tmp);
	ICharacter* bob = new Character("bob");
	zaz->use(0, *bob);
	zaz->use(1, *bob);
	delete bob;
	delete zaz;
	delete src;
	std::cout << "---------- Test - XP System ----------" << std::endl;
	IMateriaSource* src2 = new MateriaSource();
	ICharacter* bob2 = new Character("Super Bob");
	src2->learnMateria(new Ice());
	src2->learnMateria(new Cure());
	ICharacter* rambo = new Character("Rambo");
	AMateria* tmp1 = src2->createMateria("ice");
	AMateria* tmp2 = src2->createMateria("cure");
	AMateria* tmp3 = src2->createMateria("cure");
	AMateria* tmp4 = src2->createMateria("cure");
	AMateria* tmp5 = src2->createMateria("cure");
	rambo->equip(tmp1);
	rambo->equip(tmp2);
	std::cout << "XP of ice : " << tmp1->getXP() << std::endl;
	rambo->use(0, *bob2);
	std::cout << "XP of ice : " << tmp1->getXP() << std::endl;
	rambo->use(0, *bob2);
	std::cout << "XP of ice : " << tmp1->getXP() << std::endl;
	std::cout << "XP of cure : " << tmp2->getXP() << std::endl;
	rambo->use(1, *bob2);
	std::cout << "XP of cure : " << tmp2->getXP() << std::endl;
	rambo->use(1, *bob2);
	std::cout << "XP of cure : " << tmp2->getXP() << std::endl;
	std::cout << "--------- Test - Character (do nothing) ----------" << std::endl;
	rambo->equip(tmp3);
	rambo->equip(tmp4);
	rambo->equip(tmp5);
	rambo->use(5, *bob2);
	rambo->use(-1, *bob2);
	rambo->unequip(0);
	rambo->use(0, *bob2);
	rambo->unequip(-5);
	rambo->unequip(12);
	std::cout << "--------- Test - Character (use) ----------" << std::endl;
	rambo->equip(tmp1);
	rambo->use(0, *bob2);
	delete rambo;
	delete src2;
	delete tmp5;
	delete bob2;
	return 0;
}
