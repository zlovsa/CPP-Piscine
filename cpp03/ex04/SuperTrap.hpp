#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP
# include <string>
# include "NinjaTrap.hpp"
# include "FragTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap
{
public:
	SuperTrap();
	SuperTrap(std::string const &name);
	SuperTrap(SuperTrap const &other);
	SuperTrap &operator=(SuperTrap const &other);
	~SuperTrap();
	using FragTrap::rangedAttack;
	using NinjaTrap::meleeAttack;

protected:
	using FragTrap::_hit_points;
	using FragTrap::_max_hit_points;
	using NinjaTrap::_energy_points;
	using NinjaTrap::_max_energy_points;
	using NinjaTrap::_melee_attack_damage;
	using FragTrap::_ranged_attack_damage;
	using FragTrap::_armor_damage_reduction;
};

#endif