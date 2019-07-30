#include <iostream>
#include <string>

template <typename F>
void function1(F & parameter) { parameter++; }

template <typename F>
void function2(F & parameter) { parameter = '*';}

void function3(char & parameter) { parameter = 'X'; }

template <typename A, typename L>
void iter(A *array, L length, void(*f)(A & )) {
	L i;

	if (!array || !length || !f)
		return;
	i = 0;
	while (i < length) {
		f(array[i]);
		i++;
	}
}

template <typename T, typename L>
void	print_array(T array, L length) {
	L i;

	i = 0;
	while (i < length) {
		std::cout << array[i] << " ";
		i++;
	}
	std::cout << std::endl;
}

int main(void) {
	char array1[4] = {'s', 'd', 'r', 's'};
	int  array2[6] = {12, -5, 14, 74521531, 0, 42};

	std::cout << "array initial : ";
	print_array(array1, 4);
	iter(array1, static_cast<long>(4), &function1);
	std::cout << "array + function1 : ";
	print_array(array1, 4);

	std::cout << "array initial : ";
	print_array(array2, 6);
	iter(array2, static_cast<size_t>(6), &function1);
	std::cout << "array + function1 : ";
	print_array(array2, 6);

	std::cout << "array initial : ";
	print_array(array1, 4);
	iter(array1, 4, &function3);
	std::cout << "array + function3 : ";
	print_array(array1, 4);

	std::cout << "array initial : ";
	print_array(array2, 6);
	iter(array2, 6, &function2);
	std::cout << "array + function2 : ";
	print_array(array2, 6);
	return 0;
}
