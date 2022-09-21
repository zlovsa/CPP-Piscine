#include <iostream>
#include <string>

void memoryLeak()
{
	std::string *panther = new std::string("String panther");
	std::cout << *panther << std::endl;

	// there must be
	delete panther;
	// leaks otherwise
}

int main(void)
{
	memoryLeak();
	std::cout << "Check 'leaks a.out' in another terminal, then press Enter." << std::endl;
	std::cin.get();
	return 0;
}