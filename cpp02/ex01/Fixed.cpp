#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(int const intval)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = intval << this->_fracBits;
}

Fixed::Fixed(float const floatval)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(floatval * (1 << this->_fracBits));
}

Fixed::Fixed(Fixed const &other)
{
	std::cout << "Copy constructor called" << std::endl;
	// next string misses "Assignation ..."
	//this->_value = other.getRawBits();
	// next string gives "Assignation ..."
	*this = other;
}

Fixed &Fixed::operator=(Fixed const &other)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_value = other.getRawBits();
	return *this;
}

std::ostream &operator<<(std::ostream &o, Fixed const &f)
{
	o << f.toFloat();
	return o;
}

int Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

int Fixed::toInt(void) const
{
	return (int)roundf(this->toFloat());
}

float Fixed::toFloat(void) const
{
	return (float)this->_value / (1 << this->_fracBits);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
