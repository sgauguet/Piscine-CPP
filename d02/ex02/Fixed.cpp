#include "Fixed.hpp"

Fixed::Fixed(void) :  _value(0) {
}

Fixed::Fixed(int const n) :  _value(n * 256) {
}

Fixed::Fixed(float const r) :  _value(roundf(r * 256)) {
}

Fixed::Fixed(Fixed const & i) {
	*this = i;
	return ;
}

Fixed::~Fixed( void ) {
}

Fixed & Fixed::operator=(Fixed const & rhs) {
	this->_value = rhs.getRawBits();
	return *this;
}

bool	Fixed::operator>(Fixed const & b) const {
	if (this->getRawBits() > b.getRawBits())
		return true;
	return false ;
}

bool	Fixed::operator<(Fixed const & b) const {
	if (this->getRawBits() < b.getRawBits())
		return true;
	return false ;
}

bool	Fixed::operator>=(Fixed const & b) const {
	if (this->getRawBits() >= b.getRawBits())
		return true;
	return false ;
}

bool	Fixed::operator<=(Fixed const & b) const {
	if (this->getRawBits() <= b.getRawBits())
		return true;
	return false ;
}

bool	Fixed::operator==(Fixed const & b) const {
	if (this->getRawBits() == b.getRawBits())
		return true;
	return false ;
}

bool	Fixed::operator!=(Fixed const & b) const {
	if (this->getRawBits() != b.getRawBits())
		return true;
	return false ;
}

Fixed 	Fixed::operator+(Fixed const & b) const {
	return this->toFloat() + b.toFloat();
}

Fixed 	Fixed::operator-(Fixed const & b) const {
	return this->toFloat() - b.toFloat();
}

Fixed 	Fixed::operator*(Fixed const & b) const {
	return this->toFloat() * b.toFloat();
}

Fixed 	Fixed::operator/(Fixed const & b) const {
	return this->toFloat() / b.toFloat();
}

Fixed & Fixed::operator++(void) {
	this->_value++;
	return *this;
}

Fixed  Fixed::operator++(int) {
	Fixed result = *this;
	++(*this);
	return result;
}

Fixed & Fixed::operator--(void) {
	this->_value--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed result = *this;
	--(*this);
	return result;
}

int Fixed::getRawBits(void) const {
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

Fixed const &	Fixed::min(Fixed const & v1, Fixed const & v2) {
	if (v1.getRawBits() < v2.getRawBits())
		return v1;
	return v2;
}

Fixed const &	Fixed::max(Fixed const & v1, Fixed const & v2) {
	if (v1.getRawBits() > v2.getRawBits())
		return v1;
	return v2;
}

Fixed &	Fixed::min(Fixed & v1, Fixed & v2) {
	if (v1.getRawBits() < v2.getRawBits())
		return v1;
	return v2;
}

Fixed &	Fixed::max(Fixed & v1, Fixed & v2) {
	if (v1.getRawBits() > v2.getRawBits())
		return v1;
	return v2;
}