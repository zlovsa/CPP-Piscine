#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include "Squad.hpp"
#include <iostream>

void print(ISquad *sq)
{
	std::cout << "squad " << sq << std::endl;
	for (int i = 0; i < sq->getCount(); ++i)
	{
		ISpaceMarine *cur = sq->getUnit(i);
		std::cout << "marine " << cur << std::endl;
	}
}

int main()
{
	ISpaceMarine *bob = new TacticalMarine;
	ISpaceMarine *jim = new AssaultTerminator;

	Squad *vlc = new Squad;
	vlc->push(bob);
	vlc->push(jim);
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine *cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}

	ISpaceMarine *john = new TacticalMarine;
	Squad *sq2 = new Squad;
	sq2->push(john);

	std::cout << std::endl
			  << "--- BEFORE ASSIGN ---" << std::endl;
	print(vlc);
	print(sq2);

	std::cout << std::endl
			  << "--- ASSIGN BEGIN ---" << std::endl;
	*vlc = *sq2;

	std::cout << std::endl
			  << "--- AFTER ASSIGN ---" << std::endl;
	print(vlc);
	print(sq2);

	std::cout << std::endl
			  << "getUnit(2)=" << vlc->getUnit(2) << std::endl;
	std::cout << "getCount()=" << vlc->getCount() << std::endl
			  << std::endl;

	delete sq2;
	delete vlc;

	return 0;
}