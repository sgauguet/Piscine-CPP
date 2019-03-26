#include "ZombieHorde.hpp"

int main() {
	int number;

	number = 15;
	ZombieHorde horde = ZombieHorde(number);
	horde.announce();
	return 0;
}