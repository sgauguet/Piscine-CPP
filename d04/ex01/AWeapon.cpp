#include "AWeapon.hpp"

AWeapon::AWeapon(void) : _name("Default"), _APCost(0), _damage(0) {
	//std::cout << "(default constructor)" << std::endl;
	return ;
}

AWeapon::AWeapon(std::string const &name, int apcost, int damage) : _name(name), _APCost(apcost), _damage(damage) {
	//std::cout << "Weapon " << name << " is created !" << std::endl;
	return ;
}

AWeapon::AWeapon(AWeapon const & copy) {
	*this = copy;
	std::cout << "AWeapon " << this->_name << " is copied." << std::endl;
	return ;
}

AWeapon::~AWeapon( void ) {
	//std::cout << "Weapon " << this->_name << " is destructed !" << std::endl;
	return ;
}

AWeapon & AWeapon::operator=(AWeapon const & b) {
	this->_name = b._name;
	this->_APCost = b._APCost;
	this->_damage = b._damage;
	return *this;
}

std::string AWeapon::getName(void) const {
	return this->_name;
}

int AWeapon::getAPCost(void) const {
	return this->_APCost;
}

int AWeapon::getDamage(void) const {
	return this->_damage;
}

void AWeapon::setName(std::string name) {
	this->_name = name;
}

void AWeapon::setAPCost(int apcost) {
	this->_APCost = apcost;
}

void AWeapon::setDamage(int damage) {
	this->_damage = damage;
}
