#ifndef AWEAPON_HPP
# define AWEAPON_HPP
# include <string>

class AWeapon
{
public:
	AWeapon(std::string const &name, int apcost, int damage);
	virtual ~AWeapon();
	std::string const &getName() const;
	int getAPCost() const;
	int getDamage() const;
	virtual void attack() const = 0;

private:
	AWeapon();
	AWeapon(AWeapon const &other);
	AWeapon &operator=(AWeapon const &other);
	std::string _name;
	int _apcost;
	int _damage;
};

#endif
