#include "StripMiner.hpp"

StripMiner::StripMiner(void) {
	return ;
}

StripMiner::StripMiner(StripMiner const & copy) {
	*this = copy;
	std::cout << "StripMiner is copied." << std::endl;
	return ;
}

StripMiner::~StripMiner( void ) {
	return ;
}

StripMiner & StripMiner::operator=(StripMiner const &) {
	return *this;
}

void StripMiner::mine(IAsteroid* target) {
	std::cout << "* strip mining ... got " << target->beMined(this) << " ! *" << std::endl;
}
