#include "Human.hpp"

Human::Human() : _brain(42)
{
	return;
}

Human::~Human()
{
	return;
}

std::string Human::identify() const
{
	return this->_brain.identify();
}

const Brain& Human::getBrain() const
{
	return this->_brain;
}