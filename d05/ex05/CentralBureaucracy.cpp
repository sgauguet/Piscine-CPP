#include "CentralBureaucracy.hpp"

CentralBureaucracy::CentralBureaucracy(void) {
	int i;

	i= 0;
	this->_offices = new OfficeBlock[20];
	this->_queue = new std::string[150];
	while (i < 20) {
		this->_offices[i].setIntern(*new Intern());
		i++;
	}
	i = 0;
	while (i < 150) {
		this->_queue[i] = "";
		i++;
	}
	return ;
}

CentralBureaucracy::CentralBureaucracy(CentralBureaucracy const & copy) {
	*this = copy;
	return ;
}

CentralBureaucracy::~CentralBureaucracy(void) {
	delete [] this->_offices;
	delete [] this->_queue;
	return ;
}

CentralBureaucracy & CentralBureaucracy::operator=(CentralBureaucracy const & b) {
	this->_offices = b._offices;
	return *this;
}

void CentralBureaucracy::addSigner(const char *name, int grade) {
	int i;

	i = 0;
	while (i < 20) {
		if (!this->_offices[i].getSigner()) {
			this->_offices[i].setSigner(*new Bureaucrat(name, grade));
			break;
		}
		i++;
	}
}

void CentralBureaucracy::addExecutor(const char *name, int grade) {
	int i;

	i = 0;
	while (i < 20) {
		if (!this->_offices[i].getExecutor()) {
			this->_offices[i].setExecutor(*new Bureaucrat(name, grade));
			break;
		}
		i++;
	}
}

void CentralBureaucracy::queueUp(std::string name) {
	int i;

	i = 0;
	while (i < 150) {
		if (this->_queue[i].length() == 0) {
			this->_queue[i] = name;
			break;
		}
		i++;
	}
}

void CentralBureaucracy::doBureaucracy(void) {
	int random_number, max_value = 0, min_value = 0, i = 0;
	const char *random_form[] = { "robotomy request", "shrubbery creation", "presidential pardon" };

	while (max_value < 20) {
		if (!this->_offices[max_value].getSigner() || !this->_offices[max_value].getExecutor())
			break;
		max_value++;
	}
	if (max_value == 0)
		return;
	while (i < 150) {
		if (this->_queue[i].length() == 0)
			break;
		random_number = rand() % (max_value - min_value) + min_value;
		this->_offices[random_number].doBureaucracy(random_form[random_number % 3] , this->_queue[i]);
		std::cout << std::endl;
		i++;
	}
}
