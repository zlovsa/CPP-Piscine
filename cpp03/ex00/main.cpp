#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
	std::srand(std::time(nullptr));
	FragTrap q("Ranger");

	q.rangedAttack("Shub-Niggurath");
	q.meleeAttack("Chthon");
	q.takeDamage(50);
	q.takeDamage(50);
	q.takeDamage(50);
	q.beRepaired(40);
	q.beRepaired(40);
	q.beRepaired(40);
	q.vaulthunter_dot_exe("Spawn");
	q.vaulthunter_dot_exe("Zombie");
	q.vaulthunter_dot_exe("Ogre");
	q.vaulthunter_dot_exe("Fiend");
	q.vaulthunter_dot_exe("Shambler");

	return (0);
}
