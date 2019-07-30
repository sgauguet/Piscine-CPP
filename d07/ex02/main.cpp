#include "Array.tpp"

int main(void) {
	unsigned int size = 150;
	Array<unsigned long> a;
	Array<unsigned long> b(10);
	Array<char> c(size);
	Array<char> d(c);
	Array<int> empty;
	unsigned int i = 0;


	std::cout << "size a : " << a.size() << std::endl;
	std::cout << "size b : " << b.size() << std::endl;
	std::cout << "size c : " << c.size() << std::endl;
	std::cout << "size d (copy c ) : " << d.size() << std::endl;
	a = b;
	std::cout << "size a ( assignation b ): " << a.size() << std::endl;
	while (i < b.size()) {
		b[i] = 42;
		i++;
	}
	i = 0;
	while (i < c.size()){
		c[i] = 42;
		i++;
	}
	std::cout << "a[7] : " << b[7] << std::endl;
	std::cout << "b[7] : " << b[7] << std::endl;
	std::cout << "c[7] : '" << c[7] << "'" << std::endl;
	std::cout << "d[7] : '" << d[7] << "'" << std::endl;
	try {
		empty[0] = -1;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
