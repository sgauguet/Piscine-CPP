#include "ScalarConversion.hpp"

int main(int argc, char **argv) {
	ScalarConversion cast;
	if (argc != 2) {
		std::cout << "Bad number of arguments" << std::endl;
		return 1;
	}
	if (cast.detectType(argv[1]) == "unknown") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return 1;
	}
	cast.printValue(argv[1]);
	return 0;
}
