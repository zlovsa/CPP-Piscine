#include "Contact.class.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact(void)
{
	return;
}

Contact::~Contact(void)
{
	return;
}

std::string Contact::getFirstName() const{ return fields[0]; }
std::string Contact::getLastName() const{ return fields[1]; }
std::string Contact::getNickName() const{ return fields[2]; }
std::string Contact::getLogin() const{ return fields[3]; }
std::string Contact::getPostalAddress() const{ return fields[4]; }
std::string Contact::getEmailAddress() const{ return fields[5]; }
std::string Contact::getPhoneNumber() const{ return fields[6]; }
std::string Contact::getBirthdayDate() const{ return fields[7]; }
std::string Contact::getFavoriteMeal() const{ return fields[8]; }
std::string Contact::getUnderwearColor() const{ return fields[9]; }
std::string Contact::getDarkestSecret() const{ return fields[10]; }
void Contact::setFirstName(std::string &s){ fields[0]=s; }
void Contact::setLastName(std::string &s){ fields[1]=s; }
void Contact::setNickName(std::string &s){ fields[2]=s; }
void Contact::setLogin(std::string &s){ fields[3]=s; }
void Contact::setPostalAddress(std::string &s){ fields[4]=s; }
void Contact::setEmailAddress(std::string &s){ fields[5]=s; }
void Contact::setPhoneNumber(std::string &s){ fields[6]=s; }
void Contact::setBirthdayDate(std::string &s){ fields[7]=s; }
void Contact::setFavoriteMeal(std::string &s){ fields[8]=s; }
void Contact::setUnderwearColor(std::string &s){ fields[9]=s; }
void Contact::setDarkestSecret(std::string &s){ fields[10]=s; }

void Contact::print_field(std::string field) const
{
	if (field.length() > 10)
	{
		field.resize(10);
		field.back() = '.';
	}
	std::cout << "|" << std::right << std::setw(10) << field;
}

void Contact::print_row(void) const
{
	for (int j = 0; j < 3; j++)
		print_field(this->fields[j]);
	std::cout << "|" << std::endl;
}

void Contact::print_header(void) const
{
	static std::string field_names[FIELDS_COUNT] =
		{"first name", "last name", "nickname", "login", "postal address",
		 "email address", "phone number", "birthday date", "favorite meal",
		 "underwear color", "darkest secret"};

	for (int j = 0; j < 3; j++)
		print_field(field_names[j]);
	std::cout << "|" << std::endl;
}

void Contact::read_contact(void)
{
	static std::string field_names[FIELDS_COUNT] =
		{"first name", "last name", "nickname", "login", "postal address",
		 "email address", "phone number", "birthday date", "favorite meal",
		 "underwear color", "darkest secret"};

	for (int i = 0; i < FIELDS_COUNT; i++)
	{
		if(std::cin.eof())
			return;
		std::cout << "Enter " << std::setw(17) << std::right << field_names[i] << " : ";
		std::getline(std::cin, this->fields[i]);
		if(std::cin.eof())
			return;
	}
}

void Contact::print_col(void) const
{
	static std::string field_names[FIELDS_COUNT] =
		{"first name", "last name", "nickname", "login", "postal address",
		 "email address", "phone number", "birthday date", "favorite meal",
		 "underwear color", "darkest secret"};

	for (int i = 0; i < FIELDS_COUNT; i++)
		std::cout << std::right << std::setw(17) << field_names[i] << " : " << this->fields[i] << std::endl;
}
