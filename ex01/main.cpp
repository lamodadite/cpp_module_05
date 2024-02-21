#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat a("a", 2);
		Form f1("f1", 2, 1);
		std::cout << f1 << std::endl;
		a.signForm(f1);
		Form f2("f2", 1, 1);
		a.signForm(f2);
		Form f3("f3", 0, 0);
		Form f4("f4", 166, 4);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}