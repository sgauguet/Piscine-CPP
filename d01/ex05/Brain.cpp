#include "Brain.hpp"

Brain::Brain(void) {
	std::ostringstream result;

	result << this;
	this->_brain_adress = result.str();
	//_displayTimestamp(1);
}

Brain::~Brain( void ) {
	//_displayTimestamp();
}

std::string Brain::identify(void) const {
	return this->_brain_adress;
}

void	Brain::_displayTimestamp(int event) {
	time_t rawtime;
	struct tm * timeinfo;
 	char buffer [20];
 	time (&rawtime);
 	timeinfo = localtime (&rawtime);
 	strftime (buffer, 20,"%Y-%m-%d %H:%M:%S",timeinfo);
 	event ? std::cout << "Brain created : " << "[" << buffer << "] " << std::endl
 	: std::cout << "Brain destructed : " << "[" << buffer << "] " << std::endl;
}