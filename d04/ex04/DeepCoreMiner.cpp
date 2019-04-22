#include "DeepCoreMiner.hpp"

DeepCoreMiner::DeepCoreMiner(void) {
	return ;
}

DeepCoreMiner::DeepCoreMiner(DeepCoreMiner const & copy) {
	*this = copy;
	std::cout << "DeepCoreMiner is copied." << std::endl;
	return ;
}

DeepCoreMiner::~DeepCoreMiner( void ) {
	return ;
}

DeepCoreMiner & DeepCoreMiner::operator=(DeepCoreMiner const &) {
	return *this;
}

void DeepCoreMiner::mine(IAsteroid* target) {
	std::cout << "* mining deep ... got " << target->beMined(this) << " ! *" << std::endl;
}
