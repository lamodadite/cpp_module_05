#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	/*
	• ShrubberyCreationForm: Required grades: sign 145, exec 137
	• RobotomyRequestForm: Required grades: sign 72, exec 45
	• PresidentialPardonForm: Required grades: sign 25, exec 5
	*/
	ShrubberyCreationForm	shrubbery("home");
	ShrubberyCreationForm	shrubbery2("garden");
	RobotonmyRequestForm	robotomy("robot");
	PresidentialPardonForm	pardon("Yoon");

	Bureaucrat				a("a", 130); //only can shrubbery
	Bureaucrat				b("b", 70); //can shrubbery, robotomy sign
	Bureaucrat				c("c", 30); //can shrubbery, robotomy
	Bureaucrat				d("d", 2); // can do anything
	Bureaucrat				e("e", 150); //can't do anything

	std::cout << std::endl << "-------------------- execute unsigned form test -------------------" << std::endl;
	a.executeForm(shrubbery);
	c.executeForm(robotomy);
	d.executeForm(pardon);

	d.signForm(shrubbery);
	d.signForm(shrubbery2);
	d.signForm(robotomy);
	d.signForm(pardon);

	std::cout << std::endl << "-------------------- execute SHRUBBERY test -------------------" << std::endl;
	e.executeForm(shrubbery);
	a.executeForm(shrubbery);
	c.executeForm(shrubbery2);

	std::cout << std::endl << "-------------------- execute ROBOTOMY test -------------------" << std::endl;
	a.executeForm(robotomy);
	b.executeForm(robotomy);
	c.executeForm(robotomy);
	
	std::cout << std::endl << "-------------------- execute PARDON test -------------------" << std::endl;
	a.executeForm(pardon);
	d.executeForm(pardon);
}