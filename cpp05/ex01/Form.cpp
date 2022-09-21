#include <iostream>
#include <sstream>
#include "Form.hpp"

Form::Form(std::string const &name, int signGrade, int executeGrade) : 
	_name(name),
	_signGrade(signGrade),
	_executeGrade(executeGrade),
	_signed(false)
{
	if (this->_signGrade < 1 || this->_executeGrade < 1)
		throw Form::GradeTooHighException();
	if (this->_signGrade > 150 || this->_executeGrade > 150)
		throw Form::GradeTooLowException();
}

Form::~Form()
{
}

std::string const &Form::getName() const
{
	return this->_name;
}

bool Form::getSigned() const
{
	return this->_signed;
}

int Form::getSignGrade() const
{
	return this->_signGrade;
}

int Form::getExecuteGrade() const
{
	return this->_executeGrade;
}

void Form::beSigned(Bureaucrat &b)
{
	if (this->_signed)
		std::cout << "Form " << this->_name << " already signed!" << std::endl;
	else if (b.getGrade() <= this->_signGrade)
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &o, Form const &f)
{
	o << "Form " << f.getName();
	if(f.getSigned())
		o << " SIGNED";
	else
		o << " NOT SIGNED";
	o << ", sign grade: " << f.getSignGrade()
	<< ", execute grade: " << f.getExecuteGrade() << ".";
	return o;
}
