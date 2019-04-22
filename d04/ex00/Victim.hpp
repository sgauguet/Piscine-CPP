#ifndef VICTIM_H
#define VICTIM_H

#include <iostream>

class Victim {

public:

	Victim(std::string name);
	Victim(Victim const & copy);
	virtual ~Victim(void);
	Victim & operator=(Victim const & b);

	std::string getName(void) const;
	std::string getTitle(void) const;
	virtual void getPolymorphed(void) const;

protected:

	Victim(void);
	std::string _name;

};

std::ostream & operator<<(std::ostream & o, Victim const & rhs); // rhs = right-hand-side

#endif
