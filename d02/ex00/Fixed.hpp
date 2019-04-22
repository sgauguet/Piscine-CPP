#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {

public: 

	Fixed(void);
	Fixed(Fixed const & copy);
	~Fixed(void);
	Fixed & operator=(Fixed const & rhs);

	int getRawBits(void) const;
	void setRawBits(int const raw);

private:

	int _value;
	static const int  _f; // Number of fractional bits

};
 
#endif
