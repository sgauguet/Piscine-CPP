#include "AsteroBocal.hpp"

AsteroBocal::AsteroBocal(void) : _name("AsteroBocal") {
	return ;
}

AsteroBocal::AsteroBocal(AsteroBocal const & copy) {
	*this = copy;
	std::cout << "AsteroBocal is copied." << std::endl;
	return ;
}

AsteroBocal::~AsteroBocal( void ) {
	return ;
}

AsteroBocal & AsteroBocal::operator=(AsteroBocal const & b) {
	this->_name = b._name;
	return *this;
}

std::string AsteroBocal::beMined(DeepCoreMiner *) const {
	return "Thorite";
}

std::string AsteroBocal::beMined(StripMiner *) const {
	return "Flavium";
}

std::string AsteroBocal::getName(void) const {
	return this->_name;
}
