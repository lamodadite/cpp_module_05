#include "RobotomyRequestForm.hpp"

RobotonmyRequestForm::RobotonmyRequestForm(std::string target) : AForm("RobotonmyRequestForm", 72, 45)
{
	this->target = target;
	std::cout << "RobotonmyRequestForm " << AForm::getName() << " is constructed" << std::endl;
}

RobotonmyRequestForm::RobotonmyRequestForm(const RobotonmyRequestForm &obj) : AForm("RobotonmyRequestForm", 72, 45)
{
	this->target = obj.target;
	std::cout << "RobotonmyRequestForm " << AForm::getName() << " is constructed by copy" << std::endl;
}

RobotonmyRequestForm& RobotonmyRequestForm::operator=(const RobotonmyRequestForm &obj)
{
	this->target = obj.target;
	std::cout << "RobotonmyRequestForm " << AForm::getName() << " is cpied by operator = " << std::endl;
	return *this;
}

RobotonmyRequestForm::~RobotonmyRequestForm()
{
	std::cout << "RobotonmyRequestForm " << AForm::getName() << " is destructed" << std::endl;
}

void RobotonmyRequestForm::execute(const Bureaucrat &executor) const
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