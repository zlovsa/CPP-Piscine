#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>

class Bureaucrat
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
	Bureaucrat(std::string const &name, int grade);
	virtual ~Bureaucrat();
	std::string const &getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();

private:
	Bureaucrat();
	Bureaucrat(Bureaucrat const &other);
	Bureaucrat &operator=(Bureaucrat const &other);
	std::string const _name;
	int _grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &b);

#endif