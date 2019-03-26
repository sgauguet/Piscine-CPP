
#include <iostream> 

int default_behavious() {

	const char	*def;
	int			i;

	def = "* loud and unbearable feedback noise *\n";
	i = 0;
	while (def[i]) {
		std::cout << (char)std::toupper(def[i]);
		i++;
	}
	return 0;
}

int main(int argc, char **argv) {

	int		i;

	if (argc < 2)
		return default_behavious();
	while (*++argv) {
		i = 0;
		while (*(*argv + i)) {
			std::cout << (char)std::toupper(*(*argv + i));
			i++;
		}
	}
	std::cout << std::endl;
	return 0;
}
