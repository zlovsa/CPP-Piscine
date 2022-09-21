#include <string>
#include <iostream>
#include "Phonebook.class.hpp"

int main(void)
{
	std::string command;
	Phonebook phonebook;

	while (1)
	{
		std::cout << "ADD/SEARCH/EXIT? : " << std::endl;
		std::getline(std::cin, command);
		if (command == "EXIT")
			break;
		else if (command == "ADD")
			phonebook.add_contact();
		else if (command == "SEARCH")
			phonebook.search();
		else
			std::cout << "Unknown command!" << std::endl;
		if (std::cin.eof())
			break;
	}
	return 0;
}
