#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{
public:
	Character(std::string const &name);
	virtual ~Character();
	void recoverAP();
	void equip(AWeapon *weapon);
	void attack(Enemy *enemy);
	std::string const &getName() const;
	int getAP() const;
	AWeapon *getWeapon() const;

private:
	Character();
	Character(Character const &other);
	Character &operator=(Character const &other);
	std::string _name;
	int _ap;
	AWeapon *_weapon;
};

std::ostream &operator<<(std::ostream &o, Character const &c);

#endif