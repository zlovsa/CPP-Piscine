#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie(std::string name, std::string type) : _name(name), _type(type)
{
	std::cout << std::endl << "Zombie class instance with (name,type)=('"
			  << this->_name << "', '" << this->_type
			  << "') created." << std::endl;
	return;
}

Zombie::~Zombie()
{
	std::cout << "Zombie class instance with (name,type)=('"
			  << this->_name << "', '" << this->_type
			  << "') destroyed." << std::endl << std::endl;
	return;
}

void Zombie::announce() const
{
	std::cout << "<" << this->_name << " (" << this->_type
		<< ")> ! Braiiiiiiinnnssss..." << std::endl;
	return;
}