#include "../include/Intern.hpp"

Intern::Intern(void)
{
	ptr_fct[0] = &Intern::ShrubberyCreation;
	ptr_fct[1] = &Intern::RobotomyRequest;
	ptr_fct[2] = &Intern::PresidentialPardon;
	std::cout << PURPLE << ITAL << "Intern class : " << RESET << "default constructor called" << std::endl;
}

Intern::Intern(Intern const & src)
{
	(void)src;
	std::cout << PURPLE << ITAL << "Intern class : " << RESET << "copy constructor called" << std::endl;
}

Intern::~Intern(void)
{
	std::cout << PURPLE << ITAL << "Intern class : " << RESET << "destructor called" << std::endl;
}

Intern & Intern::operator=(Intern const & src)
{
	(void)src;
	std::cout << PURPLE << ITAL << "Intern class : " << RESET << "copy assignment operator called" << std::endl;
	return (*this);
}

AForm	*Intern::ShrubberyCreation(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::RobotomyRequest(std::string target)
{
	return (new RobotomyRequestForm(target));
}


AForm	*Intern::PresidentialPardon(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string formName, std::string formTarget)
{
	std::string possibleName[3] = {"robotomy request", "presidential request", "shrubbery request" };

	for (int i = 0; i < 3; i++)
	{
		if (formName == possibleName[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return ((this->*ptr_fct[i])(formTarget));
		}
	}
	std::cout << "The form name " << formName << " passed in parameter doesn't exist" << std::endl;
	return NULL;
}

// on cree un tableau de pointeur sur fonction qui contient 
// trois fonctions appelant chacune le constructeur d'un type 
// de forme avec target en parametre