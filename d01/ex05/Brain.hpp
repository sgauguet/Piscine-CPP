#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>

class Brain {

public: 

	Brain(void);
	~Brain(void);

	std::string identify (void) const;

private:

	void		_displayTimestamp(int event = 0);
	std::string _brain_adress;
};

#endif
