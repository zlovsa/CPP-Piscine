#include <iostream>
#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const &type) : _hp(hp), _type(type)
{
}

Enemy::~Enemy()
{
}

std::string const &Enemy::getType() const
{
	return this->_type;
}

int Enemy::getHP() const
{
	return this->_hp;
}

void Enemy::takeDamage(int damage)
{
	if (damage >= 0)
	{
		if (this->_hp > damage)
			this->_hp -= damage;
		else
			this->_hp = 0;
	}
}
