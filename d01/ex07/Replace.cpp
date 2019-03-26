
#include "Replace.hpp"

Replace::Replace(std::string filename) : _inputfile_name(filename), _outputfile_name(filename) {
	this->_outputfile_name.append(".replace");
	return ;
}

std::string Replace::getFileContent (std::string filename) const {
	if (filename.empty())
		filename = this->_inputfile_name;

	std::ifstream inputfile(filename.data(), std::ifstream::in);
	std::ostringstream sscontent;
	std::string content;

	if (!inputfile.good()) {
		_displayErrors(1);
		return content;
	}

	sscontent << inputfile.rdbuf();
	content = sscontent.str();
	inputfile.close();

	return content;
}

std::string Replace::getModifiedContent (std::string content, std::string s1, std::string s2) {
	size_t index = 0;

	if (content.empty() || s1.empty() || s2.empty()) {
		_displayErrors(2);
		return content;
	}
	while (1) {
		index = content.find(s1, index);
     	if (index == std::string::npos) break;
     	content.replace(index, s1.length(), s2);
     	index += s2.length();
	}

	return content;
}

void		Replace::createFile(std::string content, std::string filename) {
	if (filename.empty())
		filename = this->_outputfile_name;
	std::ofstream outputfile(filename.data(), std::ofstream::out);
	if (!outputfile.good()) {
		_displayErrors(3);
		return ;
	}
	outputfile << content;
	outputfile.close(); 
	return ;
}

void		Replace::_displayErrors(int error_code) const {
	std::string message;
	switch (error_code){
		case 1 : message = "File does not exist or can't be opened.";   break;
    	case 2: message = "File content is empty or s1/s2 is empty.";    break;
    	case 3 : message = "Output stream file error. Access denied ?";   break;
	}
	std::cout << message << std::endl;
	return ;
}
