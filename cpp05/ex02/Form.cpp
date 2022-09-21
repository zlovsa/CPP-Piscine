#include <iostream>
#include "Form.hpp"

Form::Form(std::string const &name, int signGrade, int executeGrade,
	std::string const &target) :
	_name(name),
	_signGrade(signGrade),
	_executeGrade(executeGrade),
	_signed(false),
	_target(target)
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

std::string const &Form::getTarget() const
{
	return this->_target;
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

void Form::execute(Bureaucrat const &executor) const
{
	if (!this->_signed)
		throw Form::NotSignedException();
	if (this->_executeGrade < executor.getGrade())
		throw Form::GradeTooLowException();
	this->action();
}

void Form::beSigned(Bureaucrat &b)
{
	if(this->_signed)
		std::cerr << "Form " << this->_name << " already signed!" << std::endl;
	else if (b.getGrade() <= this->_signGrade)
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &o, Form const &f)
{
	o << "Form " << f.getName();
	if(!f.getSigned())
		o << " NOT";
	o << " SIGNED, target " << f.getTarget() << ", sign grade: "
	  << f.getSignGrade() << ", execute grade: " << f.getExecuteGrade() << ".";
	return o;
}
