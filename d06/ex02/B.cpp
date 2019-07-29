#include "B.hpp"
#include <iostream> 

B::B(void) {
	std::cout << "B created" << std::endl;
	return ;
}

B::B(B const & copy) {
	*this = copy;
	return ;
}

B::~B(void) {
	return ;
}

B & B::operator=(B const &) {
	return *this;
}
