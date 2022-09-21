#include <iostream>
#include <string>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *strptr = &str;
	std::string &strref = str;
	std::cout << "String: " << str << std::endl;
	std::cout << "Pointer: " << *strptr << std::endl;
	std::cout << "Reference: " << strref << std::endl;
	return 0;
}