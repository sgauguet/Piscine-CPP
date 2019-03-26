#ifndef CAT_H
#define CAT_H

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>

class Cat {

public: 

	Cat(void);
	~Cat(void);

	std::string	getFileContent (std::string filename) const;
	void		readStandardInput(void) const;
	void		printFiles(char **argv) const;
	
private:

	void		_displayErrors(int error_code, std::string filename) const;

};
 
#endif