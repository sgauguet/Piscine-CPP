#ifndef PONY_H
#define PONY_H

#include <iostream>
#include <string>

class Pony {

public: 

	Pony(std::string name, std::string type);
	~Pony(void);

	void announce(void) const;

	std::string getPonyName (void) const;
	void setPonyName (std::string name);

private:

	std::string _pony_name;
	std::string _pony_type;

};
 
#endif
