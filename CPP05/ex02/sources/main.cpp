#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int main(void)
{
	std::cout << BOLD << "--- Creation of the three kind of forms ---" << RESET << std::endl;
	ShrubberyCreationForm shrubbery("home");
	RobotomyRequestForm robotomy("robot");
	PresidentialPardonForm president("pardon");

	std::cout << BOLD << "--- Creation of three Bureaucrates ---" << RESET << std::endl;
	Bureaucrat b1("Gagao", 2);
	Bureaucrat b2("Momo", 149);
	Bureaucrat b3("Mimi", 26);

	std::cout << BOLD << "--- Sign tests ---" << RESET << std::endl;
	std::cout << ITAL << GREY << " *Gagao shouldn't be able to sign*" << RESET << std::endl;
	b2.signForm(shrubbery);
	std::cout << ITAL << GREY << " *Mimi shouldn't be able to sign*" << RESET << std::endl;
	b3.signForm(president);
	std::cout << ITAL << GREY << " *Mimi incremente by 1*" << RESET << std::endl;
	b3.incrementeGrade();
	std::cout << ITAL << GREY << " *Mimi should be able to sign*" << RESET << std::endl;
	b3.signForm(president);
	std::cout << ITAL << GREY << " *Mimi already signed *" << RESET << std::endl;
	b3.signForm(president);
	std::cout << BOLD << "--- Signing ---" << RESET << std::endl;
	std::cout << ITAL << GREY << " *Gagao should be able to sign Robotomy*" << RESET << std::endl;
	b1.signForm(robotomy);
	std::cout << ITAL << GREY << " *Mimi should be able to sign Shrubbery*" << RESET << std::endl;
	b3.signForm(shrubbery);
	std::cout << BOLD << "--- Execution tests ---" << RESET << std::endl;
	std::cout << ITAL << GREY << " *Momo shouldn't be able to execute President*" << RESET << std::endl;
	b2.executeForm(president);
	std::cout << ITAL << GREY << " *Momo shouldn't be able to execute Shrubbery*" << RESET << std::endl;
	b2.executeForm(shrubbery);
	std::cout << ITAL << GREY << " *Momo increment by 147*" << RESET << std::endl;
	for (int i = 0; i < 147; i++)
		b2.incrementeGrade();	
	std::cout << BOLD << "--- Execution ---" << RESET << std::endl;
	std::cout << ITAL << GREY << " *Momo should be able to execute President*" << RESET << std::endl;
	b2.executeForm(president);
	std::cout << ITAL << GREY << " *Momo should be able to execute Robotomy*" << RESET << std::endl;
	b2.executeForm(robotomy);
	std::cout << ITAL << GREY << " *Momo should be able to execute Robotomy*" << RESET << std::endl;
	b2.executeForm(robotomy);
	std::cout << ITAL << GREY << " *Mimi should be able to execute Robotomy*" << RESET << std::endl;
	b3.executeForm(robotomy);
	std::cout << ITAL << GREY << " *Gagao should be able to execute Shrubbery*" << RESET << std::endl;
	try
	{
		shrubbery.execute(b1);
		std::cout << "Gagao execute Shrubbery" << std::endl ;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
	// b1.executeForm(shrubbery);


	return 0;
}