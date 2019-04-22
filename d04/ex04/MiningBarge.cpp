#include "MiningBarge.hpp"

MiningBarge::MiningBarge(void) {
	this->_lasers[0] = NULL;
	this->_lasers[1] = NULL;
	this->_lasers[2] = NULL;
	this->_lasers[3] = NULL;
	return ;
}

MiningBarge::MiningBarge(MiningBarge const & copy) {
	this->_lasers[0] = copy._lasers[0];
	this->_lasers[1] = copy._lasers[1];
	this->_lasers[2] = copy._lasers[2];
	this->_lasers[3] = copy._lasers[3];
	std::cout << "MiningBarge is copied." << std::endl;
	return ;
}

MiningBarge::~MiningBarge( void ) {
	return ;
}

MiningBarge & MiningBarge::operator=(MiningBarge const & b) {
	for (int i = 0; i < 4; i++) {
		this->_lasers[i] = b._lasers[i];
	}
	return *this;
}

void MiningBarge::equip(IMiningLaser* laser) {
	int i;

	i = 0;
	while (i < 4) {
		if (this->_lasers[i] == NULL) {
			this->_lasers[i] = laser;
			break;
		}
		i++;
	}
	return;
}

void MiningBarge::mine(IAsteroid* a) const {
	for (int i = 0; i < 4; i++) {
		if (this->_lasers[i] != NULL) {
			this->_lasers[i]->mine(a);
		}
	}
}
