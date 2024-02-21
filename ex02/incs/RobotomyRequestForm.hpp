#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotonmyRequestForm : public AForm
{
	private:
		std::string target;
		RobotonmyRequestForm();
	public:
		RobotonmyRequestForm(const RobotonmyRequestForm &obj);
		RobotonmyRequestForm &operator=(const RobotonmyRequestForm &obj);
		~RobotonmyRequestForm();
		RobotonmyRequestForm(std::string target);
		void execute(const Bureaucrat &executor) const;
};


#endif