#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
#include <string>
#include <ctime>
#include "Brain.hpp"

class Human {

public: 

	Human(void);
	~Human(void);

	Brain 		getBrain (void) const;
	std::string	identify (void) const;
	
private:

	void	_displayTimestamp(int event = 0);
	Brain 	const _brain;
};
 
#endif