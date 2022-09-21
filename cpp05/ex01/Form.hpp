#ifndef FORM_HPP
# define FORM_HPP
# include <string>
# include "Bureaucrat.hpp"

class Form
{
public:
	class GradeTooHighException : public std::exception	{
	public:
		virtual const char *what() const throw() {
			return "Grade is too high";
		}
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw() {
			return "Grade is too low";
		}
	};
	Form(std::string const &name, int signGrade, int executeGrade);
	virtual ~Form();
	std::string const &getName() const;
	bool getSigned() const;
	int getSignGrade() const;
	int getExecuteGrade() const;
	void beSigned(Bureaucrat &b);

private:
	Form();
	Form(Form const &other);
	Form &operator=(Form const &other);
	std::string const _name;
	int const _signGrade;
	int const _executeGrade;
	bool _signed;
};

std::ostream &operator<<(std::ostream &o, Form const &f);

#endif