#include "ZombieEvent.hpp"

int main() {
	int 		i;
	ZombieEvent event;

	for (i = 0; i < 5; i++) {
		event.randomChump();
	}
	Zombie *first = event.newZombie("Jean-Marie");
	first->announce();
	delete first;
	return 0;
}
