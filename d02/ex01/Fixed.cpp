#include "Fixed.hpp"

Fixed::Fixed(void) :  _value(0) {
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(int const n) :  _value(n * 256) {
	std::cout << "Int Constructor called" << std::endl;
}

Fixed::Fixed(float const r) :  _value(roundf(r * 256)) {
	std::cout << "Float Constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & copy) {
	std::cout << "Copy Constructor called" << std::endl;
	*this = copy;
	return ;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(Fixed const & rhs) {
	std::cout << "Assignation operator called" << std::endl;
	this->_value = rhs.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const {
	//std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

float Fixed::toFloat( void ) const {
	float result;
	result = this->toInt();
	result += (float)(this->_value & 0x0000ff) / 256 ;
	return result;
}

int Fixed::toInt( void ) const {
	return roundf(this->_value >> this->_f);
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs) {
	o << rhs.toFloat();
	return o;
}

int const Fixed::_f = 8;
