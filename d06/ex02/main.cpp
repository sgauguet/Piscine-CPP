#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
	int random_number, max_value = 4, min_value = 1;

	random_number = rand() % (max_value - min_value) + min_value;
	if (random_number == 1) {
		return new A;
	}
	else if (random_number== 2)
		return new B;
	else
		return new C;
}

void identify_from_pointer( Base * p) {
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else 
		std::cout << "????" << std::endl;
}

void identify_from_reference( Base & p) {
	if (dynamic_cast<A *>(&p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(&p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(&p))
		std::cout << "C" << std::endl;
	else 
		std::cout << "????" << std::endl;
}


int main(void) {
	srand(static_cast<unsigned int>(time(NULL)));
	Base *ptr;

	ptr = generate();
	std::cout << "identify_from_pointer : ";
	identify_from_pointer(ptr);
	std::cout << "identify_from_reference : ";
	identify_from_reference(*ptr);
	delete ptr;
	return 0;
}
