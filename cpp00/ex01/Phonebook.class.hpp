#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H
# include <string>
# include "Contact.class.hpp"
# define MAX_CONTACTS 8

class Phonebook
{

public:
	Phonebook(void);
	~Phonebook(void);
	void add_contact(void);
	void search(void) const;

private:
	Contact contacts[MAX_CONTACTS];
	int contact_count;
	void print_phonebook(void) const;
	bool is_number(const std::string &s) const;
	void print_delimeter(void) const;
};

#endif