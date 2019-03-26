#ifndef REPLACE_H
#define REPLACE_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

class Replace {

public: 

	Replace(std::string filename);

	std::string	getFileContent (std::string filename = "") const;
	std::string	getModifiedContent (std::string content, std::string const s1, std::string const s2) ;
	void		createFile(std::string content, std::string filename = "");
	
private:

	void		_displayErrors(int error_code) const;

	std::string _inputfile_name;
	std::string _outputfile_name;

};
 
#endif