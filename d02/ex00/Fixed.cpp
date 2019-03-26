#include "Fixed.hpp"

Fixed::Fixed(void) :  _value(0) {
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & i) {
	std::cout << "Copy Constructor called" << std::endl;
	*this = i;
	return ;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(Fixed const & rhs) {
	std::cout << "Assignation operator called" << std::endl;
	this->_value = rhs.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}