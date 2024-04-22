#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/Intern.hpp"

int main(void)
{
	Intern someRandomIntern;
	AForm* rrf;
	AForm* ppf;
	AForm* scf;
	AForm* nonValid;

	std::cout << BOLD << "-- Making a robotomy request --" << RESET << std::endl;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << BOLD << "-- Making a presidential request --" << RESET << std::endl;
	ppf = someRandomIntern.makeForm("presidential request", "Bibi");
	std::cout << BOLD << "-- Making a shrubbery request --" << RESET << std::endl;
	scf = someRandomIntern.makeForm("shrubbery request", "Momo");
	std::cout << BOLD << "-- Making a non valid request --" << RESET << std::endl;
	nonValid = someRandomIntern.makeForm("bla bla", "nonValid");
	nonValid = someRandomIntern.makeForm("", "nonValid");

	delete rrf;
	delete ppf;
	delete scf;
	return 0;
}