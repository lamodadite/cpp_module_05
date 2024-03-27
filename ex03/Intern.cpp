#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &obj)
{
	(void) obj;
}

Intern& Intern::operator=(const Intern &obj)
{
	(void) obj;
	return *this;
}

AForm	*Intern::newShrubberyCreation(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm	*Intern::newRobotomyRequest(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm	*Intern::newPresidentialPardon(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeForm(std::string type, std::string name)
{
	std::string formNames[3] = {"ShrubberyCreation", "RobotomyRequest", "PresidentialPardon"};
	AForm* (Intern::*f[3])(std::string);
	f[0] = &Intern::newShrubberyCreation;
	f[1] = &Intern::newRobotomyRequest;
	f[2] = &Intern::newPresidentialPardon;

	for (int i = 0; i < 3; i++)
	{
		if (formNames[i] == type)
		{
			std::cout << "Intern creates " << type << std::endl;
			return (this->*f[i])(name);
		}
	}
	throw Intern::FormNotExistException();
}

const char *Intern::FormNotExistException::what(void) const throw()
{
	return ("Form isn't exist");
}