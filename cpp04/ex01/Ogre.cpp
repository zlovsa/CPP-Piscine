#include <iostream>
#include "Ogre.hpp"

Ogre::Ogre() : Enemy(120, "Ogre")
{
	std::cout << "* UAAARRRRGGHH!!!!! *" << std::endl;
}

Ogre::~Ogre()
{
	std::cout << "* Ogre died *" << std::endl;
}

void Ogre::takeDamage(int damage)
{
	Enemy::takeDamage(damage - 8);
}
