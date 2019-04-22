
#include <iostream>
#include <string>

int main(void) {

	std::string str = "HI THIS IS BRAIN";
	std::string	*ptr = &str;
	std::string	&ref = str;

	std::cout << "Display with pointer : " << *ptr << std::endl;
	std::cout << "Display with reference : " << ref << std::endl;
	return 0;
}
