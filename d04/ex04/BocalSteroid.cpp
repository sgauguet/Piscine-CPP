#include "BocalSteroid.hpp"

BocalSteroid::BocalSteroid(void) : _name("BocalSteroid") {
	return ;
}

BocalSteroid::BocalSteroid(BocalSteroid const & copy) {
	*this = copy;
	std::cout << "BocalSteroid is copied." << std::endl;
	return ;
}

BocalSteroid::~BocalSteroid( void ) {
	return ;
}

BocalSteroid & BocalSteroid::operator=(BocalSteroid const & b) {
	this->_name = b._name;
	return *this;
}

std::string BocalSteroid::beMined(DeepCoreMiner *) const {
	return "Zazium";
}

std::string BocalSteroid::beMined(StripMiner *) const {
	return "Krpite";
}

std::string BocalSteroid::getName(void) const {
	return this->_name;
}
