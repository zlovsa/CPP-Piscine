#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"

void WriteLine(std::string msg)
{
	std::cout << msg << std::endl;
}

void tryForm(std::string name, int sgrade, int xgrade)
{
	std::cout << "Form " << name << "(\"" << name << "\", "
			  << sgrade << ", " << xgrade << ");" << std::endl;
	try
	{
		Form f(name, sgrade, xgrade);
		std::cout << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void tryFormSign(Form *f, Bureaucrat *b)
{
	std::cout << *f << std::endl
			  << *b << std::endl;
	try
	{
		f->beSigned(*b);
		f->beSigned(*b);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << *f << std::endl
			  << std::endl;
	delete f;
	delete b;
}

void tryBureSign(Form *f, Bureaucrat *b)
{
	std::cout << *f << std::endl
			  << *b << std::endl;
	b->signForm(*f);
	b->signForm(*f);
	std::cout << *f << std::endl
			  << std::endl;
	delete f;
	delete b;
}

int main()
{
	WriteLine("--- Normal constructor functioning ---");
	tryForm("f28c", 80, 50);
	WriteLine("--- Too high grade constructor functioning ---");
	tryForm("f29c", 0, 50);
	tryForm("f29c", 80, 0);
	tryForm("f29c", 0, 0);
	WriteLine("--- Too low grade constructor functioning ---");
	tryForm("f29c", 180, 50);
	tryForm("f29c", 80, 250);
	tryForm("f29c", 180, 250);

	WriteLine("--- Normal form sign functioning ---");
	tryFormSign(new Form("F28B", 80, 50), new Bureaucrat("Bob", 60));
	WriteLine("--- Too low grade sign functioning ---");
	tryFormSign(new Form("F28B", 80, 50), new Bureaucrat("Bob", 90));

	WriteLine("--- Normal bureaucrat sign functioning ---");
	tryBureSign(new Form("F28C", 80, 50), new Bureaucrat("Bob", 60));
	WriteLine("--- Too low grade bureaucrat sign functioning ---");
	tryBureSign(new Form("F28C", 80, 50), new Bureaucrat("Bob", 90));

	return 0;
}