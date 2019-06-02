#ifndef FORM_H
# define FORM_H

#include <iostream>
#include <exception>

class Bureaucrat;
#include "Bureaucrat.hpp"

class Form {

public:

	Form(void);
	Form(std::string name, int sign, int exec);
	Form(Form const & copy);
	virtual ~Form(void);
	Form & operator=(Form const & b);

	std::string const getName(void) const;
	bool getSigned(void) const;
	int getGradeSign(void) const;
	int getGradeExec(void) const;
	void beSigned(Bureaucrat & a);

	class GradeTooHighException : public std::exception 
	{
	public:
		GradeTooHighException(void);
		GradeTooHighException(GradeTooHighException const & copy);
		~GradeTooHighException(void) throw();
		GradeTooHighException & operator=(GradeTooHighException const & b);
		virtual const char * what() const throw();
	};

	class GradeTooLowException : public std::exception 
	{
	public:
		GradeTooLowException(void);
		GradeTooLowException(GradeTooLowException const & copy);
		~GradeTooLowException(void) throw();
		GradeTooLowException & operator=(GradeTooLowException const & b);
		virtual const char * what() const throw();
	};

private:

	std::string const _name;
	int const _grade_sign;
	int const _grade_exec;
	bool _signed;

};

std::ostream & operator<<(std::ostream & o, Form const & rhs); // rhs = right-hand-side

#endif
