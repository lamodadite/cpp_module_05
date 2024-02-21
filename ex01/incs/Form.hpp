#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string name;
		bool isSigned;
		const int gradeSign;
		const int gradeExec;
		Form();
		Form& operator=(const Form &obj);
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
		Form(std::string const &name, int gradeSign, int gradeExec);
		Form(const Form &obj);
		~Form();
		void beSigned(Bureaucrat &bureaucrat);
		std::string getName() const;
		bool getIsSigned() const;
		int getGradeSign() const;
		int getGradeExec() const;
};

std::ostream& operator<<(std::ostream &os, const Form &obj);

#endif