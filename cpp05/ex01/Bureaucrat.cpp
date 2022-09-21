#include <iostream>
#include <sstream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name), _grade(grade)
{
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
}

std::string const &Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void Bureaucrat::signForm(Form &f)
{
	if (f.getSigned())
		std::cout << "Form " << f.getName() << " already signed!" << std::endl;
	else
		try
		{
			f.beSigned(*this);
			std::cout << this->_name << " signs " << f.getName() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << this->_name << " cannot sign " << f.getName()
					  << " because " << e.what() << std::endl;
		}
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &b)
{
	o << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return o;
}
