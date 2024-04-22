#include "../include/Bureaucrat.hpp"

void	TestForm(std::string name, const int to_sign, const int to_exec)
{
	std::cout << "-- Trying to create a form named " << name << " with a grade required to sign of " << to_sign << " and a grade required to execute " << to_exec << " --" << std::endl;
	try 
	{
		Form f(name, to_sign, to_exec);
		std::cout << f << " successfully created !" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception : " << e.what() << RESET << std::endl;
	}
}

int main(void)
{
	std::cout << std::endl << BOLD << "*** Form test with default constructor ***" << RESET << std::endl;
	{
		Form	f;
		std::cout << "Default form is: " << f;
	}
	std::cout << std::endl << BOLD << "*** Form test with name, grade required to sign and to execute initialization constructor ***" << RESET << std::endl;
	{
		// should succeed
		TestForm("form1", 10, 100);
		TestForm("form2", 3, 48);
		// should fail
		TestForm("form3", -8, 1);
		TestForm("form4", 90, 0);
		TestForm("form5", 151, 2);
		TestForm("form6", 50, 180);
	}
	std::cout << std::endl << BOLD << "*** Form test copy constructor ***" << RESET << std::endl;
	{
		Form f("Normal form", 98, 100);
		std::cout << " Form is " << f << std::endl;
		Form fCopy(f);
		std::cout << " Form is " << fCopy << std::endl;

	}
	// std::cout << std::endl << BOLD << "*** Form test copy assignement ***" << RESET << std::endl;
	// {
	// 	Form f("Mimi", 64, 47);
	// 	Form fCopy;
	// 	std::cout << " Form is " << f << std::endl;
	// 	std::cout << " Form is " << fCopy << std::endl;
	// 	fCopy = f;
	// 	std::cout << " Form is " << fCopy << std::endl;
	// }
	std::cout << std::endl << BOLD << "*** Test Bureaucrat to sign Form ***" << RESET << std::endl;
	{
		Form f1("Average form", 75, 75);
		Form f2("Easy form", 140, 140);
		Form f3("Hard form", 10, 10);

		Bureaucrat b1("Gagao", 20);
		Bureaucrat b2("Momo", 142);
		Bureaucrat b3("Mimi", 10);

		std::cout << std::endl;
		b1.signForm(f1);
		std::cout << std::endl;
		b1.signForm(f1);
		std::cout << std::endl;
		b1.signForm(f3);
		std::cout << std::endl;
		b2.signForm(f2);
		std::cout << std::endl;
		b3.signForm(f3);
		std::cout << std::endl;
	}
	return 0;
}