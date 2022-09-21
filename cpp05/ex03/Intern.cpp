#include <iostream>
#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
	this->_sources[0].formname = "robotomy request";
	this->_sources[0].create = &Intern::createRobotomyRequest;
	this->_sources[1].formname = "presidential pardon";
	this->_sources[1].create = &Intern::createPresidentialPardon;
	this->_sources[2].formname = "shrubbery creation";
	this->_sources[2].create = &Intern::createShrubberyCreation;
}

Intern::~Intern()
{
}

Form *Intern::makeForm(std::string const &formname,
					   std::string const &target) const
{
	int i = 0;
	while (i < 3 && this->_sources[i].formname != formname)
		i++;
	if (i < 3)
	{
		Form *form = (this->*_sources[i].create)(target);
		std::cout << "Intern creates " << formname << std::endl;
		return form;
	}
	std::cerr << "Intern cannot create " << formname
			  << " because form not found" << std::endl;
	throw Intern::FormNotFoundException();
}

Form *Intern::createPresidentialPardon(std::string const &target) const
{
	return new PresidentialPardonForm(target);
}

Form *Intern::createRobotomyRequest(std::string const &target) const
{
	return new RobotomyRequestForm(target);
}

Form *Intern::createShrubberyCreation(std::string const &target) const
{
	return new ShrubberyCreationForm(target);
}
