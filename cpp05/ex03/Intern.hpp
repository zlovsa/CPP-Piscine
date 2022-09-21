#ifndef INTERN_HPP
# define INTERN_HPP
# include <string>
# include "Form.hpp"

class Intern
{
public:
	class FormNotFoundException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Form not found";
		}
	};
	Intern();
	virtual ~Intern();
	virtual Form *makeForm(std::string const &formname,
						   std::string const &target) const;

private:
	Intern(Intern const &other);
	Intern &operator=(Intern const &other);
	typedef struct list {
		std::string formname;
		Form *(Intern::*create)(std::string const &) const;
	} s_list;
	s_list _sources[3];
	Form *createPresidentialPardon(std::string const &target) const;
	Form *createRobotomyRequest(std::string const &target) const;
	Form *createShrubberyCreation(std::string const &target) const;
};

#endif