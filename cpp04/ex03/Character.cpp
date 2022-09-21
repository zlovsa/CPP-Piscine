#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"

Character::Character() : _name("default")
{
	this->_materias_init();
}

Character::Character(std::string const &name) : _name(name)
{
	this->_materias_init();
}

void Character::_materias_init()
{
	for (int i = 0; i < 4; i++)
		this->_materias[i] = nullptr;
	this->_materiacount = 0;
}

Character::Character(Character const &other)
{
	*this = other;
}

Character &Character::operator=(Character const &other)
{
	this->_materias_delete();
	for (int i = 0; i < other._materiacount; ++i)
		this->equip(other._materias[i]->clone());
	this->_name = other._name;
	return *this;
}

Character::~Character()
{
	this->_materias_delete();
}

std::string const &Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria *m)
{
	if (this->_materiacount == 4 || !m)
		return;
	this->_materias[this->_materiacount++] = m;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= this->_materiacount)
		return;
	this->_materias[idx] = nullptr;
	this->_materiacount--;
	while (idx < this->_materiacount)
	{
		this->_materias[idx] = this->_materias[idx + 1];
		idx++;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= this->_materiacount)
		return;
	this->_materias[idx]->use(target);
}

void Character::_materias_delete()
{
	for (int i = 0; i < this->_materiacount; i++)
		delete this->_materias[i];
	this->_materiacount = 0;
}

void Character::Announce()
{
	std::cout << this << " : " << this->_name << std::endl
			  << "Materias:" << std::endl;
	for (int i = 0; i < this->_materiacount;i++)
		std::cout << i << " : " << this->_materias[i]->getType()
				  << " - " << this->_materias[i] << "; XP="
				  << this->_materias[i]->getXP() << std::endl;
}