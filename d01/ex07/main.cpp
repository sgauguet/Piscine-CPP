
#include "Replace.hpp"

void	replace(std::string filename, std::string s1, std::string s2) {
	Replace f = Replace(filename);
	std::string content;
	std::string newcontent;

	content = f.getFileContent();
	newcontent = f.getModifiedContent(content, s1, s2);
	if (!newcontent.empty())
		f.createFile(newcontent);
}

int		checkParameters(char **argv) {
	std::string filename;
	std::string s1;
	std::string	s2;

	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	if (filename.empty() || s1.empty() || s2.empty()) {
		std:: cout << "Parameters must not be empty.\n" ;
		return 1;
	}
	replace(filename, s1, s2);
	return 0;
}

int 	main(int argc, char **argv) {

	if (argc < 4){
		std:: cout << "usage: ./replace filename s1 (string to replace in file) s2 (new string) \n" ;
		return 1;
	}
	checkParameters(argv);
	return 0;
}
