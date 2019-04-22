#include "Character.hpp"

Character::Character(void) : _name("Default"), _AP(40), _ptr(NULL) {
	//std::cout << "(default constructor)" << std::endl;
	return ;
}

Character::Character(std::string const & name) : _name(name), _AP(40), _ptr(NULL) {
	//std::cout << "Character " << name << "is created !" << std::endl;
	return ;
}

Character::Character(Character const & copy) {
	*this = copy;
	std::cout << "Character " << this->_name << " is copied." << std::endl;
	return ;
}

Character::~Character( void ) {
	std::cout << "Character " << this->_name << " is destructed !" << std::endl;
	return ;
}

Character & Character::operator=(Character const & b) {
	this->_name = b._name;
	this->_AP = b._AP;
	this->_ptr = b._ptr;
	return *this;
}

void Character::recoverAP(void) {
	this->_AP += 10;
	if (this->_AP > 40)
		this->_AP = 40;
}

void Character::equip(AWeapon* ptr) {
	this->_ptr = ptr;
}

void Character::attack(Enemy* a) {
	if (this->_ptr == NULL || !a->getHP())
		return;
	if (this->_AP - this->_ptr->getAPCost() >= 0) {
		std::cout << this->_name << " attacks " << a->getType() << " with a "<< this->_ptr->getName() << std::endl;
		this->_AP -= this->_ptr->getAPCost();
		this->_ptr->attack();
		a->takeDamage(this->_ptr->getDamage());
		if (a->getHP() <= 0)
			delete a;
	}
}

std::string Character::getName(void) const {
	return this->_name;
}

int Character::getAP(void) const {
	return this->_AP;
}

AWeapon * Character::getWeapon(void) const {
	return this->_ptr;
}

std::ostream & operator<<(std::ostream & o, Character const & rhs) {
	AWeapon *tmp =  rhs.getWeapon();
	if (tmp)
		o << rhs.getName() << " has " << rhs.getAP() << " AP and wields a " << tmp->getName() << std::endl;
	else
		o << rhs.getName() << " has " << rhs.getAP() << " AP and is unarmed" << std::endl;
	return o;
}
