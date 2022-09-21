#include <string>
#include <iostream>
#include <iomanip>
#include "Phonebook.class.hpp"

Phonebook::Phonebook(void)
{
	this->contact_count = 0;
}

Phonebook::~Phonebook(void)
{
	return;
}

void Phonebook::print_delimeter(void)const
{
	std::string l = "+----------";
	std::cout << l << l << l << l << "+" << std::endl;
}

void Phonebook::print_phonebook(void) const
{
	print_delimeter();
	std::cout << "|     index";
	this->contacts[0].print_header();
	print_delimeter();
	for (int i = 0; i < this->contact_count; i++)
	{
		std::cout << "|         " << i;
		this->contacts[i].print_row();
	}
	print_delimeter();
}

void Phonebook::add_contact(void)
{
	if (this->contact_count < MAX_CONTACTS)
		this->contacts[this->contact_count++].read_contact();
	else
		std::cout << "Maximum of " << MAX_CONTACTS << " contacts reached." << std::endl;
}

bool Phonebook::is_number(const std::string &s) const
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it))
		++it;
	return !s.empty() && it == s.end();
}

void Phonebook::search(void) const
{
	int idx;
	std::string idx_str;

	if (!this->contact_count)
	{
		std::cout << "Phonebook is empty." << std::endl;
		return;
	}
	print_phonebook();
	std::cout << "Enter index of contact to view: ";
	std::getline(std::cin, idx_str);
	if(std::cin.eof())
		return;
	idx = atoi(idx_str.c_str());
	if (is_number(idx_str) && 0 <= idx && idx < this->contact_count)
		this->contacts[idx].print_col();
	else
		std::cout << "Wrong index!" << std::endl;
	return;
}