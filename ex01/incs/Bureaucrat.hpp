#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Form;

class Bureaucrat
{
	private:
		std::string const name;
		int grade;
		Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat &obj);
	public:
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(const Bureaucrat &obj);
		~Bureaucrat();
		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(Form &form);
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &obj);

#endif