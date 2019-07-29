#ifndef SCALARCONVERSION_H
#define SCALARCONVERSION_H

#include <iostream>
#include <sstream>
#include <iomanip>
#include <cfloat> 
#include <string>
#include <exception>
#include <climits>

class ScalarConversion {

public:

	ScalarConversion(void);
	ScalarConversion(ScalarConversion const & copy);
	virtual ~ScalarConversion(void);
	ScalarConversion & operator=(ScalarConversion const & b);

	bool		isChar(const std::string argv);
	bool		isInt(const std::string argv);
	bool		isFloat(const std::string argv);
	bool		isDouble(const std::string argv);
	bool		isInf(const std::string argv);
	bool		isInfNeg(const std::string argv);
	bool		isNan(const std::string argv);

	void 		convertChar(const std::string & argv);
	void		convertInt(const std::string & argv);
	void 		convertFloat(const std::string & argv);
	void 		convertDouble(const std::string & argv);

	std::string detectType(const char *argv);
	void print_pseudo_literals(const std::string & argv);
	void print_literals(int overflow[3]);
	void printValue(const char *argv);

private:

	char _c;
	int _i;
	float _f;
	double _d;
	bool _infn;
	bool _inf;
	bool _nan;
	std::string _type;

};

#endif
