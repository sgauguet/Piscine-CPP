
#include "Logger.hpp"

 Logger::Logger (std::string logfile) : _logfile(logfile) {
	return ;
}

void Logger::logToConsole (std::string message) {
	if (message.empty()) {
		return ;
	}
	std::cout << message << std::endl;
}

void Logger::logToFile (std::string message) {
	std::ofstream outputfile(this->_logfile.data(), std::ofstream::app);
	if (!outputfile.good() || message.empty()) {
		return ;
	}
	outputfile << message << std::endl;
	outputfile.close(); 
	return ;
}

std::string Logger::makeLogEntry (std::string message) {
	time_t rawtime;
	struct tm * timeinfo;
	std::string new_message;
 	char buffer[21];
 	time (&rawtime);
 	timeinfo = localtime (&rawtime);
 	strftime (buffer, 20,"%Y-%m-%d %H:%M:%S",timeinfo);
 	buffer[19] = ' ';
 	buffer[20] = '\0';
 	new_message = buffer;
 	new_message.append(message);
 	return new_message;
}

void Logger::log (std::string const & dest, std::string const & message) {
	void (Logger::*f[2])(std::string message);
	std::string dests[2] = { "file", "console" };
	std::string entry;
	int	i = 0;

	entry = this->makeLogEntry(message);
	f[0] = &Logger::logToFile;
	f[1] = &Logger::logToConsole;
	
	while (i < 2) {
		if (dests[i] == dest) {
			(this->*f[i])(entry);
			break ;
		}
		i++;
	}
}