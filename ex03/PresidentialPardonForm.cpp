#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 72, 45)
{
	this->target = target;
	std::cout << "PresidentialPardonForm " << AForm::getName() << " is constructed" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm("PresidentialPardonForm", 72, 45)
{
	this->target = obj.target;
	std::cout << "PresidentialPardonForm " << AForm::getName() << " is constructed by copy" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
	this->target = obj.target;
	std::cout << "PresidentialPardonForm " << AForm::getName() << " is cpied by operator = " << std::endl;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm " << AForm::getName() << " is destructed" << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (getIsSigned() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getGradeSign() || executor.getGrade() > getGradeExec())
		throw (Bureaucrat::GradeTooLowException());
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}