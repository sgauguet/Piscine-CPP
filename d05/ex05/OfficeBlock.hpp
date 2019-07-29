#ifndef OFFICEBLOCK_H
#define OFFICEBLOCK_H

#include <iostream>
#include <exception>
#include <sstream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"

class OfficeBlock {

public:

	OfficeBlock(void);
	OfficeBlock(Intern & intern, Bureaucrat & sign, Bureaucrat & exec);
	virtual ~OfficeBlock(void);

	int getIntern(void);
	int getSigner(void);
	int getExecutor(void);
	void setIntern(Intern & intern);
	void setSigner(Bureaucrat & sign);
	void setExecutor(Bureaucrat & exec);
	void doBureaucracy(std::string formName, std::string target);

	class formException : public std::exception 
	{
	public:
		formException(void);
		formException(std::string formName);
		formException(formException const & copy);
		~formException(void) throw();
		formException & operator=(formException const & b);
		virtual const char * what() const throw();
	private:
		std::string _formName;
	};

	class paramException : public std::exception 
	{
	public:
		paramException(void);
		paramException(std::string param);
		paramException(paramException const & copy);
		~paramException(void) throw();
		paramException & operator=(paramException const & b);
		virtual const char * what() const throw();
	private:
		std::string _param;
	};

private:

	OfficeBlock(OfficeBlock const & copy);
	OfficeBlock & operator=(OfficeBlock const & b);

	Intern * _intern;
	Bureaucrat * _signingBureaucrat;
	Bureaucrat * _executingBureaucrat;
	
};

#endif
