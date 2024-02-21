#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->target = target;
	std::cout << "ShrubberyCreationForm " << AForm::getName() << " is constructed by copy" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->target = obj.target;
	std::cout << "ShrubberyCreationForm " << AForm::getName() << " is constructed by copy" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
	this->target = obj.target;
	std::cout << "ShrubberyCreationForm " << AForm::getName() << " is cpied by operator = " << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm " << AForm::getName() << " is destructed" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	std::string		outFileName;
	std::ofstream	outFile;

	if (getIsSigned() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getGradeSign() || executor.getGrade() > getGradeExec())
		throw (Bureaucrat::GradeTooLowException());
	outFileName = target + "_shruberry";
	outFile.open(outFileName.c_str());
	if (!outFile.is_open())
		throw AForm::FileOpenFailException();
	outFile << "       ^  ^  ^   ^      ___I_      ^  ^   ^  ^  ^   ^  ^\n"
				"      /|\\/|\\/|\\ /|\\    /\\-_--\\    /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\\n"
				"      /|\\/|\\/|\\ /|\\   /  \\_-__\\   /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\\n"
				"      /|\\/|\\/|\\ /|\\   |[]| [] |   /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\\n";
	outFile.close();
}


