
#include "Cat.hpp"

Cat::Cat(void) {
	
	return ;
}

Cat::~Cat(void) {
	
	return ;
}

std::string Cat::getFileContent (std::string filename) const {
	std::ifstream inputfile(filename.data(), std::ifstream::in);
	std::ostringstream sscontent;
	std::string content;
	struct stat s;
	if (!inputfile.good()) {
		_displayErrors(1, filename);
		return content;
	}
	else if (stat(filename.data(), &s) == 0 && S_ISDIR(s.st_mode)) {
		_displayErrors(2, filename);
   		return content;
	}
	sscontent << inputfile.rdbuf();
	content = sscontent.str();
	inputfile.close();
	return content;
}

void 	Cat::readStandardInput(void) const {
	std::string input;

	while (1) {
		std::getline(std::cin, input);
		std::cout << input << std::endl;
	}
}

void 	Cat::printFiles(char **argv) const {
	while (*++argv) {
		std::cout << this->getFileContent(*argv);
	}
}


void	Cat::_displayErrors(int error_code, std::string filename) const {
	std::ostringstream message;
	switch (error_code){
		case 1 : message << "cat: " << filename << ": Aucun fichier ou dossier de ce type" ; break;
		case 2 : message << "cat: " << filename << ": est un dossier" ; break;
	}
	std::cout << message.str() << std::endl;
	return ;
}
