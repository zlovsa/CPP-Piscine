#include <iostream>
#include "iter.hpp"

int main(void)
{
	int a[3] = {8, 13, 5};
	std::cout << std::endl
			  << "Int array:" << std::endl;
	::iter(a, 3, ::print);
	
	float b[5] = {0.8f, -13.01f, 5.5f, 7.0f, 0.f};
	std::cout << std::endl
			  << "Float array:" << std::endl;
	::iter(b, 5, ::print);
	std::cout << "Increment 3 elements:" << std::endl;
	::iter(b, 3, ::inc);
	::iter(b, 5, ::print);

	std::string c[4] = {"hello", "to", "iter", "template"};
	std::cout << std::endl
			  << "String array:" << std::endl;
	::iter(c, 4, ::print);

	std::cout << std::endl;

	return 0;
}