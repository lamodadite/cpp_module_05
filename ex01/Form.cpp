#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!!!!!!!!!!!!!!!!!!!!!!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!!!!!!!!!!!!!!!!!!!!!!";
}

Form::Form() : name("noname"), gradeSign(0), gradeExec(0)
{
}

Form& Form::operator=(const Form &obj)
{
	this->isSigned = obj.isSigned;
	return *this;
}

Form::Form(std::string const &name, int gradeSign, int gradeExec) : name(name), gradeSign(gradeSign), gradeExec(gradeExec)
{
	if (this->gradeSign < 1 || this->gradeExec < 1)
	{
		throw Form::GradeTooHighException();
	}
	else if (this->gradeSign > 150 || this->gradeExec > 150)
	{
		throw Form::GradeTooLowException();
	}
	std::cout << this->name << " is constructed" << std::endl;
}

Form::Form(const Form &obj) : name(obj.name), gradeSign(obj.gradeSign), gradeExec(obj.gradeExec)
{
	if (this->gradeSign < 1 || this->gradeExec < 1)
	{
		throw Form::GradeTooHighException();
	}
	else if (this->gradeSign > 150 || this->gradeExec > 150)
	{
		throw Form::GradeTooLowException();
	}
	std::cout << this->name << " is constructed by copy" << std::endl;
}

Form::~Form()
{
	std::cout << this->name << " is destructed" << std::endl;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->gradeSign)
	{
		this->isSigned = true;
	}
	else
	{
		throw GradeTooLowException();
	}
}

std::string Form::getName() const
{
	return this->name;
}

bool Form::getIsSigned() const
{
	return this->isSigned;
}

int Form::getGradeSign() const
{
	return this->gradeSign;
}

int Form::getGradeExec() const
{
	return this->gradeExec;
}

std::ostream& operator<<(std::ostream &os, const Form &obj)
{
	os << "name : " << obj.getName()
		<< "\nisSined : " << std::boolalpha << obj.getIsSigned()
		<< "\ngradeSign : " << obj.getGradeSign()
		<< "\ngradeExec : " << obj.getGradeExec()
		<< std::endl;
	return os;
}
