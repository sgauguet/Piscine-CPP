#ifndef C_H
#define C_H

#include "Base.hpp"

class C : public Base {

public:

	C(void);
	C(C const & copy);
	virtual ~C(void);
	C & operator=(C const & b);

};

#endif
