#include <iostream>
#include "Character.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "Ogre.hpp"
#include "Axe.hpp"

int main()
{
	Character *me = new Character("me");

	std::cout << *me;

	Enemy *b = new RadScorpion();

	AWeapon *pr = new PlasmaRifle();
	AWeapon *pf = new PowerFist();

	me->equip(pr);
	std::cout << *me;
	me->equip(pf);

	me->attack(b);
	std::cout << *me;
	me->equip(pr);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;

	Character *ranger = new Character("Ranger");
	std::cout << *ranger;

	Enemy *sm = new SuperMutant();
	Enemy *ogre = new Ogre();

	AWeapon *axe = new Axe();
	ranger->equip(axe);
	std::cout << *ranger;

	ranger->attack(sm);
	std::cout << *ranger;
	ranger->attack(ogre);
	std::cout << *ranger;

	return 0;
}