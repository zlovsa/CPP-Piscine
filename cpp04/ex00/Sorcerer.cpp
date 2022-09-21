#include <iostream>
#include <sstream>
#include "Sorcerer.hpp"

Sorcerer::Sorcerer()
{
}

Sorcerer::Sorcerer(std::string const &name, std::string const &title) :
	_name(name), _title(title)
{
	std::cout << this->_name << ", " << this->_title << ", is born!"
		<< std::endl;
}

Sorcerer::Sorcerer(const Sorcerer &other)
{
	*this = other;
}

Sorcerer &Sorcerer::operator=(Sorcerer const &other)
{
	this->_name = other._name;
	this->_title = other._title;
	return *this;
}

Sorcerer::~Sorcerer()
{
	std::cout << this->_name << ", " << this->_title
		<< ", is dead. Consequences will never be the same!" << std::endl;
}

std::string const &Sorcerer::getName() const
{
	return this->_name;
}

std::string const &Sorcerer::getTitle() const
{
	return this->_title;
}

void Sorcerer::polymorph(Victim const &v) const
{
	v.getPolymorphed();
}

std::ostream &operator<<(std::ostream &o, Sorcerer const &s)
{
	o << "I am " << s.getName() << ", " << s.getTitle() + ", and I like ponies!" << std::endl;
	return o;
}
