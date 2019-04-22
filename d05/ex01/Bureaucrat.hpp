#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat 
{
public:

	Bureaucrat(void);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const & copy);
	~Bureaucrat(void);
	Bureaucrat & operator=(Bureaucrat const & b);

	std::string const getName(void) const;
	int getGrade(void) const;
	void incrementGrade(void);
	void decrementGrade(void);
	void signForm(Form & form) const;

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
	int _grade;

};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs); // rhs = right-hand-side

#endif
