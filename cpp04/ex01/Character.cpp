#include <iostream>
#include "Character.hpp"

Character::Character(std::string const &name) : _name(name), _ap(40), _weapon(nullptr)
{
}

Character::~Character()
{
}

void Character::recoverAP()
{
	if (this->_ap + 10 > 40)
		this->_ap = 40;
	else
		this->_ap += 10;
}

void Character::equip(AWeapon *weapon)
{
	this->_weapon = weapon;
}

void Character::attack(Enemy *enemy)
{
	if (!this->_weapon || this->_ap < this->_weapon->getAPCost())
		return;
	this->_ap -= this->_weapon->getAPCost();
	std::cout << this->_name << " attacks "
			  << enemy->getType() << " with a "
			  << this->_weapon->getName() << std::endl;
	this->_weapon->attack();
	enemy->takeDamage(this->_weapon->getDamage());
	if (!enemy->getHP())
		delete enemy;
}

std::string const &Character::getName() const
{
	return this->_name;
}

int Character::getAP() const
{
	return this->_ap;
}

AWeapon *Character::getWeapon() const
{
	return this->_weapon;
}

std::ostream &operator<<(std::ostream &o, Character const &c)
{
	o << c.getName() << " has " << c.getAP() << " AP and ";
	if (c.getWeapon())
		o << "wields a " << c.getWeapon()->getName() << std::endl;
	else
		o << "is unarmed" << std::endl;
	return o;
}
