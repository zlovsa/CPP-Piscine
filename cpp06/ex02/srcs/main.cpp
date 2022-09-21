#include <iostream>
#include "main.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	Base *baseptr = 0;
	char choice = 'A' + rand() % 3;
	std::cout << "generated " << choice << "* pointer." << std::endl;
	if (choice == 'A')
		baseptr = new A;
	else if (choice == 'B')
		baseptr = new B;
	else if (choice == 'C')
		baseptr = new C;
	return baseptr;
}

void identify_from_pointer(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A";
	if (dynamic_cast<B *>(p))
		std::cout << "B";
	if (dynamic_cast<C *>(p))
		std::cout << "C";
}

void identify_from_reference(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A";
	}
	catch(...)
	{
	}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B";
	}
	catch (...)
	{
	}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C";
	}
	catch (...)
	{
	}
}

int main(void)
{
	srand(time(NULL));
	int testCount = 3 + rand() % 3;
	while(testCount--)
	{
		Base *p = generate();
		std::cout << "Pointer identified as ";
		identify_from_pointer(p);
		std::cout << " class" << std::endl;
		std::cout << "Reference identified as ";
		identify_from_reference(*p);
		std::cout << " class" << std::endl
				  << std::endl;
		delete p;
	}

	return 0;
}