#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

void WriteLine(std::string msg)
{
	std::cout << msg << std::endl;
}

int main()
{
	WriteLine("--- Normal constructor functioning ---");
	WriteLine("Bureaucrat robert(\"Robert\", 80);");
	WriteLine("------");
	try
	{
		Bureaucrat robert("Robert", 80);
		std::cout << robert << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	WriteLine("");
	WriteLine("--- Too high grade constructor functioning ---");
	WriteLine("Bureaucrat john(\"John\", 0);");
	WriteLine("------");
	try
	{
		Bureaucrat john("John", 0);
		std::cout << john << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	WriteLine("");
	WriteLine("--- Too low grade constructor functioning ---");
	WriteLine("Bureaucrat jim(\"John\", 200);");
	WriteLine("------");
	try
	{
		Bureaucrat jim("Jim", 200);
		std::cout << jim << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	WriteLine("");
	WriteLine("--- Too high grade through increment function ---");
	WriteLine("Bureaucrat tom(\"Tom\", 2);");
	WriteLine("tom.incrementGrade();");
	WriteLine("tom.incrementGrade();");
	WriteLine("------");
	try
	{
		Bureaucrat tom("Tom", 2);
		std::cout << tom << std::endl;
		tom.incrementGrade();
		std::cout << tom << std::endl;
		tom.incrementGrade();
		std::cout << tom << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	WriteLine("");
	WriteLine("--- Too low grade through decrement function ---");
	WriteLine("Bureaucrat mike(\"Mike\", 149);");
	WriteLine("mike.decrementGrade();");
	WriteLine("mike.decrementGrade();");
	WriteLine("------");
	try
	{
		Bureaucrat mike("Mike", 149);
		std::cout << mike << std::endl;
		mike.decrementGrade();
		std::cout << mike << std::endl;
		mike.decrementGrade();
		std::cout << mike << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}