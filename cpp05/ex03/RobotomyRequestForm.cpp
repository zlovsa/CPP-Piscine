#include <iostream>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : 
	Form("RobotomyRequestForm", 72, 45, target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::action() const
{
	std::cout << "* Some drilling noises *" << std::endl
			  << this->getTarget()
			  << " has been robotomized successfully 50 % of the time."
			  << std::endl;
}
