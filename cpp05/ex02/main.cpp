#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void WriteLine(std::string msg)
{
	std::cout << msg << std::endl;
}

void tryFormExec(Form *f, Bureaucrat *signer, Bureaucrat *executor)
{
	std::cout << *f << std::endl
			  << "Signer: " << *signer << std::endl
			  << "Executor: " << *executor << std::endl;
	try
	{
		f->beSigned(*signer);
		std::cout << *f << std::endl;
		f->execute(*executor);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	delete f;
	delete signer;
	delete executor;
}

void tryBureExec(Form *f, Bureaucrat *signer, Bureaucrat *executor)
{
	std::cout << *f << std::endl
			  << "Signer: " << *signer << std::endl
			  << "Executor: " << *executor << std::endl;
	signer->signForm(*f);
	std::cout << *f << std::endl;
	executor->executeForm(*f);
	std::cout << std::endl;
	delete f;
	delete signer;
	delete executor;
}

int main()
{
	WriteLine("--- Normal form execute functioning ---");
	tryFormExec(new ShrubberyCreationForm("home"),
				new Bureaucrat("Tom", 140),
				new Bureaucrat("Joe", 130));
	WriteLine("--- Too low grade form sign functioning ---");
	tryFormExec(new RobotomyRequestForm("John"),
				new Bureaucrat("Bob", 80),
				new Bureaucrat("Jim", 30));
	WriteLine("--- Too low grade form exec functioning ---");
	tryFormExec(new RobotomyRequestForm("John"),
				new Bureaucrat("Bob", 70),
				new Bureaucrat("Jim", 50));
	WriteLine("--- Normal bureuaucrat exec functioning ---");
	tryBureExec(new PresidentialPardonForm("Timmy"),
				new Bureaucrat("Bob", 20),
				new Bureaucrat("Alice", 2));
	WriteLine("--- Too low grade bureuaucrat sign functioning ---");
	tryBureExec(new PresidentialPardonForm("Jimmy"),
				new Bureaucrat("Shaun", 30),
				new Bureaucrat("Alice", 2));
	WriteLine("--- Too low grade bureuaucrat exec functioning ---");
	tryBureExec(new ShrubberyCreationForm("garden"),
				new Bureaucrat("Shaun", 30),
				new Bureaucrat("Neo", 140));

	return 0;
}