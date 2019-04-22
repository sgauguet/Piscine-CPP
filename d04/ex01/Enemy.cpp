#include "Enemy.hpp"

Enemy::Enemy(void) : _type("unknown"), _HP(0) {
	//std::cout << "Enemy (default constructor)" << std::endl;
	return ;
}

Enemy::Enemy(int hp, std::string const & type) : _type(type), _HP(hp) {
	//std::cout << "Enemy is created !" << std::endl;
	return ;
}

Enemy::Enemy(Enemy const & copy) {
	*this = copy;
	std::cout << "Enemy is copied." << std::endl;
	return ;
}

Enemy::~Enemy( void ) {
	return ;
}

Enemy & Enemy::operator=(Enemy const & b) {
	this->_type = b._type;
	this->_HP = b._HP;
	return *this;
}

std::string Enemy::getType(void) const {
	return this->_type;
}

int Enemy::getHP(void) const {
	return this->_HP;
}

void Enemy::setType(std::string type) {
	this->_type = type;
}

void Enemy::setHP(int hp) {
	this->_HP = hp;
}

void Enemy::takeDamage(int amount) {
	int damage = amount;
	if (damage <= 0)
		return ;
	this->setHP(this->getHP() - damage);
	if (this->getHP() < 0 ) {
		this->setHP(0);
	}
}
