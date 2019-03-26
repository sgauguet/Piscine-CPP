
#include "Pony.hpp"

void ponyOnTheHeap (std::string name) {
	Pony *heap = new Pony(name, "heap");
	std::cout << "Hey, i'm " << heap->getPonyName() << std::endl;
	delete heap;
}

void ponyOnTheStack (std::string name) {
	Pony stack = Pony(name, "stack");
	std::cout << "Hey, i'm " << stack.getPonyName() << "!!" << std::endl;
}

int main() {
	ponyOnTheStack("Stack1");
	ponyOnTheStack("Stack2");
	ponyOnTheHeap("Heap1");
	ponyOnTheHeap("Heap2");
	return 0;
}