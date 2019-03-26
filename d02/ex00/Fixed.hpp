#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {

public: 

	Fixed(void);
	Fixed(Fixed const & i);
	~Fixed(void);

	Fixed & operator=(Fixed const & rhs);
	int getRawBits(void) const;
	void setRawBits(int const raw);

private:

	int _value;
	static const int  f = 8; // Number of fractional bits

};
 
#endif