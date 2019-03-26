
#include "Human.hpp"

void Human::meleeAttack (std::string const & target) {
	std::cout << "melee Attack against " << target << "." << std::endl;
}

void Human::rangedAttack (std::string const & target) {
	std::cout << "ranged Attack against " << target << "." << std::endl;
}

void Human::intimidatingShout (std::string const & target) {
	std::cout << "intimidating shout against " << target << "." << std::endl;
}

void Human::action (std::string const & action_name, std::string const & target) {
	void (Human::*f[3])(std::string const & target);
	std::string attacks[3] = { "meleeAttack", "rangedAttack", "intimidatingShout" };
	int i;

	f[0] = &Human::meleeAttack;
	f[1] = &Human::rangedAttack;
	f[2] = &Human::intimidatingShout;
	i = 0;

	while (i < 3) {
		if (attacks[i] == action_name) {
			(this->*f[i])(target);
			break ;
		}
		i++;
	}
}