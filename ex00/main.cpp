#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat test1("test1", 200);
		Bureaucrat test2("test2", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat a("a", 1);
		Bureaucrat b("b", 150);
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << "============" << std::endl;
		a.incrementGrade();
		b.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}