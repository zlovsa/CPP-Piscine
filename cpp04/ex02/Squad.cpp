#include <iostream>
#include "Squad.hpp"

Squad::Squad() : _units(nullptr)
{
}

Squad::Squad(const Squad &other)
{
	*this = other;
}

Squad &Squad::operator=(Squad const &other)
{
	if (this == &other)
		return *this;
	this->_units_delete();
	s_list *t = other._units;
	while (t)
	{
		this->push(t->marine->clone());
		t = t->next;
	}
	return *this;
}

void Squad::_units_delete()
{
	s_list *t = this->_units;
	while (t)
	{
		s_list *p = t->next;
		delete t->marine;
		delete t;
		t = p;
	}
	this->_units = nullptr;
}

Squad::~Squad()
{
	this->_units_delete();
}

int Squad::getCount() const
{
	s_list *t = this->_units;
	int count = 0;
	while (t && ++count)
		t = t->next;
	return count;
}

ISpaceMarine *Squad::getUnit(int N) const
{
	if (N < 0 || N > this->getCount())
		return nullptr;
	s_list *t = this->_units;
	while (N--)
		t = t->next;
	return t->marine;
}

int Squad::push(ISpaceMarine *marine)
{
	if (!marine)
		return this->getCount();
	s_list *t = this->_units;
	while (t && t->next && t->marine != marine)
		t = t->next;
	if (t && t->marine==marine)
		return this->getCount();	
	s_list *n = new s_list;
	n->marine = marine;
	n->next = nullptr;
	if(this->_units)
		t->next = n;
	else
		this->_units = n;
	return this->getCount();
}
