#include <iostream>
#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : 
	Form("ShrubberyCreationForm", 145, 137, target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::action() const
{
	std::ofstream ofs;
	ofs.open(this->getTarget() + "_shrubbery");
	ofs << "          &&& &&  & &&" << std::endl;
	ofs << "      && &\\/&\\|& ()|/ @, &&" << std::endl;
	ofs << "      &\\/(/&/&||/& /_/)_&/_&" << std::endl;
	ofs << "   &() &\\/&|()|/&\\/ '%\" & ()" << std::endl;
	ofs << "  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
	ofs << "&&   && & &| &| /& & % ()& /&&" << std::endl;
	ofs << " ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
	ofs << "     &&     \\|||" << std::endl;
	ofs << "             |||" << std::endl;
	ofs << "             |||" << std::endl;
	ofs << "             |||" << std::endl;
	ofs << "       , -=-~  .-^- _" << std::endl;
	ofs.close();
}
