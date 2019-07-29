#ifndef CENTRALBUREAUCRACY_H
#define CENTRALBUREAUCRACY_H

#include <iostream>
#include <exception>
#include <fstream>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "OfficeBlock.hpp"

class Form;

class CentralBureaucracy {

public:

	CentralBureaucracy(void);
	CentralBureaucracy(CentralBureaucracy const & copy);
	~CentralBureaucracy(void);
	CentralBureaucracy & operator=(CentralBureaucracy const & b);

	void addSigner(const char *name, int grade);
	void addExecutor(const char *name, int grade);
	void doBureaucracy(void);

	void queueUp(std::string name);

private:

	OfficeBlock * _offices;
	std::string * _queue;

};

#endif
