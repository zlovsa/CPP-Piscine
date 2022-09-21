#include "Pony.hpp"
#include <iostream>

void ponyOnTheHeap(void)
{
	Pony *heapPony = new Pony("Heap");
	heapPony->greet();
	delete heapPony;
}

void ponyOnTheStack(void)
{
	Pony stackPony("Stack");
	stackPony.greet();
}

int main(void)
{
	ponyOnTheHeap();
	ponyOnTheStack();
	std::cout << "Check 'leaks a.out' in another terminal, then press Enter." << std::endl;
	std::cin.get();
	return 0;
}