#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>
#include <fstream>

class Logger
{

public:

	Logger(std::string logfile);

	void		log(std::string const & dest, std::string const & message);
	
private:

	void 		logToConsole(std::string message);
	void 		logToFile(std::string message);
	std::string makeLogEntry(std::string message);

	std::string _logfile;

};
 
#endif
