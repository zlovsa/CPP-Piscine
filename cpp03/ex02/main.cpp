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
	q.takeDamage(120);
	d.takeDamage(70);
	q.beRepaired(75);
	d.beRepaired(160);
	q.vaulthunter_dot_exe("Spawn");
	d.challengeNewcomer("Demon");
	q.vaulthunter_dot_exe("Ogre");
	d.challengeNewcomer("Arch-vile");
	ScavTrap b(d);
	FragTrap p=q;

	return (0);
}
