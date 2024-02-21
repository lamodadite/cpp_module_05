#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		bool isSigned;
		const int gradeSign;
		const int gradeExec;
		AForm();
		AForm& operator=(const AForm &obj);
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
		class FormNotSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class FileOpenFailException : public std::exception
		{
			public:
				const char *what() const throw();
		}
		AForm(std::string const &name, int gradeSign, int gradeExec);
		AForm(const AForm &obj);
		~AForm();
		void beSigned(Bureaucrat &bureaucrat);
		std::string getName() const;
		bool getIsSigned() const;
		int getGradeSign() const;
		int getGradeExec() const;
		virtual execute(const Bureaucrat &executor) const = 0;
};

std::ostream& operator<<(std::ostream &os, const AForm &obj);

#endif