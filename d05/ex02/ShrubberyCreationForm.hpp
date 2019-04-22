#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include <iostream>
#include <exception>
#include "Form.hpp"

class ShrubberyCreationForm : public Form {

public:

	ShrubberyCreationForm(void);
	ShrubberyCreationForm(target);
	ShrubberyCreationForm(ShrubberyCreationForm const & copy);
	~ShrubberyCreationForm(void);
	ShrubberyCreationForm & operator=(ShrubberyCreationForm const & b);

	std::string const getName(void) const;
	bool getSigned(void) const;
	int getGradeSign(void) const;
	int getGradeExec(void) const;
	void beSigned(Bureaucrat & a);

	class GradeTooHighException : public std::exception 
	{
	public:
		virtual const char * what() const throw();
	};

	class GradeTooLowException : public std::exception 
	{
	public:
		virtual const char * what() const throw();
	};

private:

	std::string const _name;
	int const _grade_sign;
	int const _grade_exec;
	bool _signed;

};

std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const & rhs); // rhs = right-hand-side

#endif
