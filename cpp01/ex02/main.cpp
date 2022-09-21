#include "ZombieEvent.hpp"
#include <string>
#include <iostream>

int main(void)
{
	Zombie* heapz;
	Zombie stackz("via_Zombie", "stack");
	ZombieEvent e;

	std::srand(std::time(nullptr));
	e.setZombieType("heap");
	e.randomChump();
	heapz = e.newZombie("via_newZombie()");
	heapz->announce();
	delete heapz;
	return 0;
}