#include <iostream>
#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include "Sheep.hpp"

int main()
{
	Sorcerer robert("Robert", "the Magnificent");

	Victim jim("Jimmy");
	Peon joe("Joe");
	Sheep shaun("Shaun");
	Peon john = joe;

	std::cout << robert << jim << joe << shaun << john;

	robert.polymorph(jim);
	robert.polymorph(joe);
	robert.polymorph(shaun);

	return 0;
}