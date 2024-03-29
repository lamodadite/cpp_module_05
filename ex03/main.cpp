#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	Intern	internA;
	Bureaucrat	master("master", 1);

	try
	{
		AForm	*shrubberyForm = internA.makeForm("ShrubberyCreation", "a");
		AForm	*robotForm = internA.makeForm("RobotomyRequest", "b");
		AForm	*pardonForm = internA.makeForm("PresidentialPardon", "c");

		master.signForm(*shrubberyForm);
		master.executeForm(*shrubberyForm);
		std::cout << std::endl;

		master.signForm(*robotForm);
		master.executeForm(*robotForm);
		std::cout << std::endl;

		master.signForm(*pardonForm);
		master.executeForm(*pardonForm);
		std::cout << std::endl;
		delete shrubberyForm;
		delete robotForm;
		delete pardonForm;
	}
	catch (std::exception &e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}
	try
	{
		AForm *wrongForm = internA.makeForm("wrong form", "wrong");

		master.signForm(*wrongForm);
		master.executeForm(*wrongForm);
	}
	catch (std::exception &e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}
}