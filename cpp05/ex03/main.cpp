#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void WriteLine(std::string msg)
{
	std::cout << msg << std::endl;
}

void tryIntern(Intern *intern, std::string const formname, std::string const target)
{
	std::cout << "intern.makeForm(\"" << formname << "\", \""
			  << target << "\");" << std::endl;
	try
	{
		Form *form = intern->makeForm(formname, target);
		std::cout << *form << std::endl;
		delete form;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int main()
{
	Intern *intern = new Intern();

	WriteLine("--- Normal intern form creation functioning ---");
	tryIntern(intern, "robotomy request", "John");
	tryIntern(intern, "presidential pardon", "Jim");
	tryIntern(intern, "shrubbery creation", "home");

	WriteLine("--- Unknown form intern creation functioning ---");
	tryIntern(intern, "strawberry creation", "garden");

	delete intern;
	return 0;
}