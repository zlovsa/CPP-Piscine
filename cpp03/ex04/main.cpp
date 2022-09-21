#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"
#include <iostream>

int main(void)
{
	std::srand(std::time(nullptr));
	FragTrap q("Ranger");
	ScavTrap d("Slayer");
	NinjaTrap b("Gordon");
	NinjaTrap p("G-Man");

	q.rangedAttack("Shub-Niggurath");
	q.takeDamage(120);
	q.beRepaired(75);
	q.vaulthunter_dot_exe("Spawn");
	q.vaulthunter_dot_exe("Ogre");

	d.meleeAttack("Cacodemon");
	d.takeDamage(70);
	d.beRepaired(160);
	d.challengeNewcomer("Demon");
	d.challengeNewcomer("Arch-vile");

	ClapTrap &t=q;
	b.ninjaShoebox(t);
	ClapTrap tmp;
	b.ninjaShoebox(tmp);
	b.ninjaShoebox(q);
	b.ninjaShoebox(d);
	b.ninjaShoebox(p);

	SuperTrap st("SupTr");
	st.vaulthunter_dot_exe("VTHtarget");
	st.ninjaShoebox(b);
	st.takeDamage(80);
	st.beRepaired(30);
	st.takeDamage(80);
	st.beRepaired(30);
	st.beRepaired(75);
	st.meleeAttack("MELEEtarget");
	st.rangedAttack("RANGEtarget");

	return (0);
}
