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
	class NotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Form not signed";
		}
	};
	Form(std::string const &name, int signGrade, int executeGrade,
		 std::string const &target);
	virtual ~Form();
	std::string const &getName() const;
	std::string const &getTarget() const;
	bool getSigned() const;
	int getSignGrade() const;
	int getExecuteGrade() const;
	void beSigned(Bureaucrat &b);
	void execute(Bureaucrat const &executor) const;

protected:
	virtual void action() const = 0;

private:
	Form();
	Form(Form const &other);
	Form &operator=(Form const &other);
	std::string const _name;
	int const _signGrade;
	int const _executeGrade;
	bool _signed;
	std::string const _target;
	void _checkGrade();
};

std::ostream &operator<<(std::ostream &o, Form const &f);

#endif