#include "Bureaucrat.hpp"
#include "AForm.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!!!!!!!!!!!!!!!!!!!!!!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!!!!!!!!!!!!!!!!!!!!!!";
}

Bureaucrat::Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &obj)
{
	this->grade = obj.grade;
	return *this;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : name(name)
{
	this->grade = grade;
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	std::cout << this->name << " is constructed" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : name(obj.name)
{
	this->grade = obj.grade;
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	std::cout << this->name << " is constructed by copy" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << this->name << " is destructed" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::incrementGrade()
{
	if (this->grade - 1 < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	this->grade -= 1;
}

void Bureaucrat::decrementGrade()
{
	if (this->grade + 1 > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	this->grade += 1;
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return os;
}

void executeForm(const AForm &form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->name << " executes " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}
