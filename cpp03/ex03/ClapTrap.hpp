#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(unsigned int hit_points,
			 unsigned int max_hit_points,
			 unsigned int energy_points,
			 unsigned int max_energy_points,
			 unsigned int level,
			 std::string const &name,
			 unsigned int melee_attack_damage,
			 unsigned int ranged_attack_damage,
			 unsigned int armor_damage_reduction,
			 std::string const &type);
	ClapTrap(ClapTrap const &other);
	ClapTrap &operator=(ClapTrap const &other);
	~ClapTrap();
	void rangedAttack(std::string const &target);
	void meleeAttack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

protected:
	unsigned int _hit_points;
	unsigned int _max_hit_points;
	unsigned int _energy_points;
	unsigned int _max_energy_points;
	unsigned int _level;
	std::string _name;
	unsigned int _melee_attack_damage;
	unsigned int _ranged_attack_damage;
	unsigned int _armor_damage_reduction;
	std::string _type;
	std::ostream &print() const;
};

#endif