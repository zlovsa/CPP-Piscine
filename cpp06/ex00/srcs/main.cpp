#include <iostream>
#include <string>
#include "ScalarConversion.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: convert <c++ literal value>" << std::endl;
		return 0;
	}
	ScalarConversion sc(argv[1]);
	sc.report();
	return 0;
}
