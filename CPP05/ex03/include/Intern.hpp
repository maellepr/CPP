#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(Intern const & src);
		~Intern(void);

		Intern & operator=(Intern const & src);
	
		AForm *ShrubberyCreation(std::string target);
		AForm *RobotomyRequest(std::string target);
		AForm *PresidentialPardon(std::string target);
		
		AForm* makeForm(std::string formName, std::string formTarget);
	private:
		typedef AForm *(Intern::*ft)(std::string target);
		ft	ptr_fct[3];
};

#endif