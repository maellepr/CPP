#include "../include/Intern.hpp"

Intern::Intern(void)
{
	std::cout << PURPLE << ITAL << "Intern class : " << RESET << "default constructor called" << std::endl;
}

Intern::Intern(Intern const & src)
{
	std::cout << PURPLE << ITAL << "Intern class : " << RESET << "copy constructor called" << std::endl;
}

Intern::~Intern(void)
{
	std::cout << PURPLE << ITAL << "Intern class : " << RESET << "destructor called" << std::endl;
}

Intern & Intern::operator=(Intert const & src)
{
	std::cout << PURPLE << ITAL << "Intern class : " << RESET << "copy assignment operator called" << std::endl;
}

Form* Intern::makeForm(std::string formName, std::string formTarget)
{
	std::cout << "Intern creates " << 
}