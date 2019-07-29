#include "A.hpp"
#include <iostream> 

A::A(void) {
	std::cout << "A created" << std::endl;
	return ;
}

A::A(A const & copy) {
	*this = copy;
	return ;
}

A::~A(void) {
	return ;
}

A & A::operator=(A const &) {
	return *this;
}
