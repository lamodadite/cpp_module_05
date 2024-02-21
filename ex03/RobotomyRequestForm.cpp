#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	this->target = target;
	std::cout << "RobotomyRequestForm " << AForm::getName() << " is constructed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm("RobotomyRequestForm", 72, 45)
{
	this->target = obj.target;
	std::cout << "RobotomyRequestForm " << AForm::getName() << " is constructed by copy" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
	this->target = obj.target;
	std::cout << "RobotomyRequestForm " << AForm::getName() << " is cpied by operator = " << std::endl;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm " << AForm::getName() << " is destructed" << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (getIsSigned() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getGradeSign() || executor.getGrade() > getGradeExec())
		throw (Bureaucrat::GradeTooLowException());
	std::srand(static_cast<unsigned>(std::time(0)));
	int	randNum = 0;
	std::cout << "GRRRRRRRRRRRRRRR" << std::endl;
	randNum = rand();
	if (randNum % 2  == 0)
	{
		std::cout << "robotomize success!!!!!!" << std::endl;
	}
	else
	{
		std::cout << " robotomize fail!!!!!!!!!!" << std::endl;
	}
}