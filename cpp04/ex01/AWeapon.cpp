#include <iostream>
#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const &name, int apcost, int damage):
	_name(name), _apcost(apcost), _damage(damage)
{
}

AWeapon::~AWeapon()
{
}

std::string const &AWeapon::getName() const
{
	return this->_name;
}

int AWeapon::getAPCost() const
{
	return this->_apcost;
}

int AWeapon::getDamage() const
{
	return this->_damage;
}
