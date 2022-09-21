#include "Pony.hpp"
#include <iostream>
#include <string>

Pony::Pony(std::string name) : _name(name)
{
	std::cout << "Pony '" << this->_name << "' created." << std::endl;
	return;
}

Pony::~Pony()
{
	std::cout << "Pony '" << this->_name << "' destroyed." << std::endl;
	return;
}

void Pony::greet() const
{
	std::cout << "Hello, my name is " << this->_name << "! Neigh!!!!" << std::endl;
	return;
}