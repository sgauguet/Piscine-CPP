#ifndef BASE_H
#define BASE_H

class Base {

public:

	Base(void);
	Base(Base const & copy);
	virtual ~Base(void);
	Base & operator=(Base const & b);

};

#endif
