#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H
# include <string>
# define FIELDS_COUNT 11

class Contact {

public:
	Contact(void);
	~Contact(void);
	void print_row(void) const;
	void print_header(void) const;
	void read_contact(void);
	void print_col(void) const;
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickName() const;
	std::string getLogin() const;
	std::string getPostalAddress() const;
	std::string getEmailAddress() const;
	std::string getPhoneNumber() const;
	std::string getBirthdayDate() const;
	std::string getFavoriteMeal() const;
	std::string getUnderwearColor() const;
	std::string getDarkestSecret() const;
	void setFirstName(std::string &s);
	void setLastName(std::string &s);
	void setNickName(std::string &s);
	void setLogin(std::string &s);
	void setPostalAddress(std::string &s);
	void setEmailAddress(std::string &s);
	void setPhoneNumber(std::string &s);
	void setBirthdayDate(std::string &s);
	void setFavoriteMeal(std::string &s);
	void setUnderwearColor(std::string &s);
	void setDarkestSecret(std::string &s);

private:
	std::string fields[FIELDS_COUNT];
	void print_field(std::string field) const;
};

#endif