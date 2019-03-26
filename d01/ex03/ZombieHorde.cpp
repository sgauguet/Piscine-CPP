#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int number) : _hord_size(number) {
    if (this->_hord_size >= 0 && this->_hord_size <= 500) {
        Zombie *zombies = new Zombie[number];

        while (number--) {
            zombies[number].setZombieName(this->getRandomName());
            zombies[number].setZombieType("random");
        }
        this->_zombies = zombies;
        std::cout << "ZombieHorde created" << std::endl;
        return ;
    }
    std::cout << "You must enter a valid zombie number (between 0 and 500)." << std::endl;
}

ZombieHorde::~ZombieHorde(void) {
    if (this->_hord_size >= 0 && this->_hord_size <= 500) {
        delete [] this->_zombies;
        std::cout << "ZombieHorde destructed" << std::endl;
    }
}

std::string ZombieHorde::getRandomName(void) {
	int 		random_number, max_value = 20, min_value = 0;
	std::string random_name;

	random_number = rand()  % max_value + min_value;
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

void	ZombieHorde::setZombieType (Zombie *zombie, std::string type) {
	zombie->setZombieType(type);
}

void    ZombieHorde::announce(void) {
    if (this->_hord_size >= 0 && this->_hord_size <= 500) {
        int number = this->_hord_size;
        Zombie *zombies = this->getZombieHorde();
        while (number--) {
            zombies[number].announce();
        }
    }
}

Zombie  *ZombieHorde::getZombieHorde(void) {
    return this->_zombies;
}