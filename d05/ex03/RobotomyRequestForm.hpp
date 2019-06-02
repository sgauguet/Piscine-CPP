#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include <iostream>
#include <exception>
#include <cstdlib>
#include "Form.hpp"

class Form;

class RobotomyRequestForm : public Form {

public:

	RobotomyRequestForm(void);
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const & copy);
	~RobotomyRequestForm(void);
	RobotomyRequestForm & operator=(RobotomyRequestForm const & b);

	void executeAction(void) const;

};

#endif
