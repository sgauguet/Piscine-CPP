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

	Fixed & operator=(Fixed const & rhs);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;

private:

	int _value;  // Fixed point value.
	static const int  _f = 8; // Number of fractional bits

};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);
 
#endif