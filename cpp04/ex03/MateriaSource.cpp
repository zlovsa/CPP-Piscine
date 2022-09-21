#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->_materias[i] = nullptr;
	this->_materiacount = 0;
}

MateriaSource::~MateriaSource()
{
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
	*this = other;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other)
{
	for (int i = 0; i < other._materiacount;i++)
		this->_materias[i] = other._materias[i]->clone();
	this->_materiacount = other._materiacount;
	return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (this->_materiacount == 4 || !m)
		return;
	this->_materias[this->_materiacount++] = m;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	int i = 0;
	while (i < this->_materiacount && this->_materias[i]->getType() != type)
		i++;
	if (i < this->_materiacount)
		return this->_materias[i]->clone();
	else
		return 0;
}
