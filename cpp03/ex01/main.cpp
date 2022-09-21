#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	std::srand(std::time(nullptr));
	FragTrap q("Ranger");
	ScavTrap d("Slayer");

	q.rangedAttack("Shub-Niggurath");
	d.meleeAttack("Cacodemon");
	q.takeDamage(80);
	d.takeDamage(70);
	q.beRepaired(75);
	d.beRepaired(60);
	q.vaulthunter_dot_exe("Spawn");
	d.challengeNewcomer("Demon");
	q.vaulthunter_dot_exe("Ogre");
	d.challengeNewcomer("Arch-vile");

	return (0);
}
