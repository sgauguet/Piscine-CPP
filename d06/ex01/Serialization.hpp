#ifndef SERIALIZATION_H
#define SERIALIZATION_H

#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <iomanip>
#include <string>
#include <time.h>
#include <climits>

struct Data { 
	std::string s1; 
	int n; 
	std::string s2; 
};

class Serialization {

public:

	Serialization(void);
	Serialization(Serialization const & copy);
	virtual ~Serialization(void);
	Serialization & operator=(Serialization const & b);

	void * serialize(void);
	Data * deserialize(void * raw);

	void 	randomArray(void);
	void	randomInt(void);
	void	printAttributes(void);


private:

	char _a1[9];
	char _a2[9];
	int _i;

};

#endif
