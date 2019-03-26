
#include "Cat.hpp"

int 	main(int argc, char **argv) {
	Cat instance;

	if (argc < 2 || (argc == 2 && std::strlen(argv[1]) == 1 && argv[1][0] == '-')) {
		instance.readStandardInput();
	}
	instance.printFiles(argv);
	return 0;
}