#include <iostream>
#include "Axe.hpp"

Axe::Axe() : AWeapon("Axe", 2, 666)
{
}

Axe::Axe(const Axe &other) :
	AWeapon(other.getName(), other.getDamage(), other.getAPCost())
{
}

Axe::~Axe()
{
}

void Axe::attack() const
{
	std::cout << "* Axe sound *" << std::endl;
}
