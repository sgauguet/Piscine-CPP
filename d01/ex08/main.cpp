
#include "Human.hpp"

int 	main(void) {

	Human human;
	std::string target = "me";

	human.action("meleeAttack", target);
	human.action("rangedAttack", target);
	human.action("intimidatingShout", target);
	human.action("intimidatingShout", target);
	human.action("meleeAttack", target);
	human.action("", target);
	human.action("unknown", target);
	human.action("error", target);

	return 0;
}