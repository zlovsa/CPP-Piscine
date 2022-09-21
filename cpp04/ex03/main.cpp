#include <iostream>
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	Character *me = new Character("me");

	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter *bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	Character *shadow = new Character("shadow");
	shadow->equip(src->createMateria("cure"));

	std::cout << std::endl
			  << "--- BEFORE COPY ---" << std::endl;
	me->Announce();
	shadow->Announce();

	std::cout << std::endl
			  << "---     COPY    ---"
			  << std::endl;
	*shadow = *me;
	me->Announce();
	shadow->Announce();

	delete bob;
	delete me;
	delete src;
	delete shadow;

	return 0;
}