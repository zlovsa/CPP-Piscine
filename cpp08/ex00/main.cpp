#include <iostream>
#include <vector>
#include <algorithm>
#include "easyfind.hpp"

void print(int const &i)
{
	std::cout << i << std::endl;
}

template <template <typename, typename> class T>
void print_cont(T<int, std::allocator<int> > const &container)
{
	for_each(container.begin(), container.end(), print);
}

void WriteLine(std::string msg)
{
	std::cout << std::endl << "--- " << msg << " ---" << std::endl;
}

int main()
{
	WriteLine("Initialize vector v:");
	std::vector<int> v;
	v.push_back(8);
	v.push_back(13);
	v.push_back(5);
	print_cont(v);

	WriteLine("*easyfind(v, 13) = 12;");
	*easyfind(v, 13) = 12;
	print_cont(v);

	WriteLine("*easyfind(v, 15) = 10;");
	try
	{
		*easyfind(v, 15) = 10;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	WriteLine("Const overload");
	const std::vector<int> cv(v);
	std::cout << *easyfind(cv, 12) << std::endl;
}