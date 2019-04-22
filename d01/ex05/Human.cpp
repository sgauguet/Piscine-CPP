#include "Human.hpp"

Human::Human(void) {
	//_displayTimestamp(1);
}

Human::~Human( void ) {
	//_displayTimestamp();
}

void	Human::_displayTimestamp(int event) {
	time_t rawtime;
	struct tm * timeinfo;
 	char buffer [20];
 	time (&rawtime);
 	timeinfo = localtime (&rawtime);
 	strftime (buffer, 20,"%Y-%m-%d %H:%M:%S",timeinfo);
 	event ? std::cout << "Human born : " << "[" << buffer << "] " << std::endl
 	: std::cout << "Human dead : " << "[" << buffer << "] " << std::endl;
}

std::string Human::identify(void) const {
	return this->_brain.identify();
}

Brain Human::getBrain (void) const {
	return this->_brain;
}
