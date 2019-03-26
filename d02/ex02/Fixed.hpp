#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed {

public: 

	Fixed(void);
	Fixed(int const n);
	Fixed(float const r);
	Fixed(Fixed const & i);
	~Fixed(void);

	Fixed & operator=(Fixed const & b);
	bool operator>(Fixed const & b) const;
	bool operator<(Fixed const & b) const;
	bool operator>=(Fixed const & b) const;
	bool operator<=(Fixed const & b) const;
	bool operator==(Fixed const & b) const;
	bool operator!=(Fixed const & b) const;

	Fixed operator+(Fixed const & rhs) const;
	Fixed operator-(Fixed const & rhs) const;
	Fixed operator*(Fixed const & rhs) const;
	Fixed operator/(Fixed const & rhs) const;

	Fixed & operator++(void); // Pre-increment
	Fixed & operator--(void); // Pre-decrement
	Fixed operator++(int i); // Post-increment
	Fixed operator--(int i); // Post-decrement

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;

	static Fixed & min(Fixed & v1, Fixed & v2);
	static Fixed & max(Fixed & v1, Fixed & v2);
	static Fixed const &	min(Fixed const & v1, Fixed const & v2);
	static Fixed const &	max(Fixed const & v1, Fixed const & v2);

private:

	int _value;  // Fixed point value.
	static const int  _f = 8; // Number of fractional bits

};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif