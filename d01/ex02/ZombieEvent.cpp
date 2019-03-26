#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(void) {
	std::cout << "ZombieEvent created" << std::endl;
}

ZombieEvent::~ZombieEvent(void) {
	std::cout << "ZombieEvent destructed" << std::endl;
}

Zombie*	ZombieEvent::newZombie(std::string name) {
	std::string input;

	Zombie *zombie = new Zombie(name);
	std::cout << "Choose zombie type: ";
	std::getline (std::cin, input);
	this->setZombieType(zombie, input);
	return zombie;
}

void ZombieEvent::randomChump(void) {
	Zombie zombie = Zombie(this->getRandomName());
	zombie.setZombieType("random");
	zombie.announce();
}

std::string ZombieEvent::getRandomName(void) {
	int 		random_number, max_value = 20, min_value = 0;
	std::string random_name;

	random_number = rand() % max_value + min_value;
	switch (random_number)
    {
    	case 0 : random_name = "Bernard" ; break;
    	case 1 : random_name = "Bianca" ; break;
    	case 2 : random_name = "Jacques" ; break;
    	case 3 : random_name = "Rufus" ; break;
    	case 4 : random_name = "Norbert" ; break;
    	case 5 : random_name = "Daisy" ; break;
    	case 6 : random_name = "Josepha" ; break;
    	case 7 : random_name = "Marie-Claude" ; break;
    	case 8 : random_name = "Monique" ; break;
    	case 9 : random_name = "Antoinette" ; break;
    	case 10 : random_name = "Alphonse" ; break;
    	case 11 : random_name = "Renée" ; break;
    	case 12 : random_name = "Marcel" ; break;
    	case 13 : random_name = "Kevin" ; break;
    	case 14 : random_name = "Cornélius" ; break;
    	case 15 : random_name = "Viviane" ; break;
    	case 16 : random_name = "Jean-Luc" ; break;
    	case 17 : random_name = "Eugène" ; break;
    	case 18 : random_name = "Claudette" ; break;
    	case 19 : random_name = "Peter" ; break;
    	default: random_name = "Anonymous" ; break;
    }
    return random_name;
}

void	ZombieEvent::setZombieType (Zombie *zombie, std::string type) {
	zombie->setZombieType(type);
}