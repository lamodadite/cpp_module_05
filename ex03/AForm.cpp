#include "AForm.hpp"

const char* AForm::GradeTooHighException::what() const throw()
{
	return "AForm Grade is too high!!!!!!!!!!!!!!!!!!!!!!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "AForm Grade is too low!!!!!!!!!!!!!!!!!!!!!!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "AForm signature is missing!!!!!!!!!!!!!!!!!";
}

const char* AForm::FileOpenFailException::what() const throw()
{
	return "File open fail!!!!!!!";
}

AForm::AForm() : name("noname"), gradeSign(0), gradeExec(0)
{
}

AForm& AForm::operator=(const AForm &obj)
{
	this->isSigned = obj.isSigned;
	return *this;
}

AForm::AForm(std::string const &name, int gradeSign, int gradeExec) : name(name), gradeSign(gradeSign), gradeExec(gradeExec)
{
	if (this->gradeSign < 1 || this->gradeExec < 1)
	{
		throw AForm::GradeTooHighException();
	}
	else if (this->gradeSign > 150 || this->gradeExec > 150)
	{
		throw AForm::GradeTooLowException();
	}
	std::cout << "AForm " << this->name << " is constructed" << std::endl;
}

AForm::AForm(const AForm &obj) : name(obj.name), gradeSign(obj.gradeSign), gradeExec(obj.gradeExec)
{
	if (this->gradeSign < 1 || this->gradeExec < 1)
	{
		throw AForm::GradeTooHighException();
	}
	else if (this->gradeSign > 150 || this->gradeExec > 150)
	{
		throw AForm::GradeTooLowException();
	}
	std::cout << this->name << " is constructed by copy" << std::endl;
}

AForm::~AForm()
{
	std::cout << this->name << " is destructed" << std::endl;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
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

std::string AForm::getName() const
{
	return this->name;
}

bool AForm::getIsSigned() const
{
	return this->isSigned;
}

int AForm::getGradeSign() const
{
	return this->gradeSign;
}

int AForm::getGradeExec() const
{
	return this->gradeExec;
}

std::ostream& operator<<(std::ostream &os, const AForm &obj)
{
	os << "name : " << obj.getName()
		<< "\nisSined : " << std::boolalpha << obj.getIsSigned()
		<< "\ngradeSign : " << obj.getGradeSign()
		<< "\ngradeExec : " << obj.getGradeExec()
		<< std::endl;
	return os;
}
