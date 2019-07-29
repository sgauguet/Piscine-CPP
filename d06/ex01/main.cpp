#include "Serialization.hpp"

int main(void) {
	srand(static_cast<unsigned int>(time(NULL)));
	Serialization s;
	void *bytes;
	Data *result;

	bytes = s.serialize();
	result = s.deserialize(bytes);
	std::cout << "----- deserialization result -----" << std::endl;
	std::cout << "s1 : " << result->s1 << std::endl;
	std::cout << "n  : " << result->n << std::endl;
	std::cout << "s2 : " << result->s2 << std::endl;
	delete [] reinterpret_cast<char *>(bytes);
	delete result;
	return 0;
}
