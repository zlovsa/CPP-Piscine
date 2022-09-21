#include <iostream>
#include <vector>
#include "span.hpp"

void WriteLine(std::string msg)
{
	std::cout << std::endl
			  << "--- " << msg << " ---" << std::endl;
}

int int_gen()
{
	return rand() % 100000 - 50000;
}

int main()
{
	WriteLine("Add by one number");
	Span sp = Span(5);
	sp.addNumber(1);
	sp.addNumber(3);
	std::cout << sp << std::endl;

	WriteLine("Add range from container");
	std::vector<int> v;
	v.push_back(17);
	v.push_back(9);
	v.push_back(11);

	sp.addRange(v.begin(), v.end());
	std::cout << sp << std::endl;

	WriteLine("Add over capacity");
	try
	{
		sp.addNumber(8);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	WriteLine("Shortest span:");
	std::cout << sp.shortestSpan() << std::endl;
	WriteLine("Longest span:");
	std::cout << sp.longestSpan() << std::endl;

	WriteLine("Large span test Span big(15000);");
	
	std::vector<int> rndv(15000);
	srand(time(NULL));
	std::generate(rndv.begin(), rndv.end(), int_gen);
	
	Span big(15000);
	big.addRange(rndv.begin(), rndv.end());

	WriteLine("Shortest span big.shortestSpan();");
	std::cout << big.shortestSpan() << std::endl;

	WriteLine("Longest span big.longestSpan();");
	std::cout << big.longestSpan() << std::endl;

	WriteLine("Span too small");
	Span sm(42);
	sm.addNumber(3);
	try
	{
		std::cout << sm << std::endl;
		std::cout << sm.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}