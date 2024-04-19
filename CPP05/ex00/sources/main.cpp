#include "../include/Bureaucrat.hpp"

void	TestBureaucrat(std::string name, int grade)
{
	std::cout << "-- Trying to create a bureaucrat named " << name << " with a grade of " << grade << " --" << std::endl;
	try 
	{
		Bureaucrat b(name, grade);
		std::cout << b << " successfully created !" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception : " << e.what() << RESET << std::endl;
	}
	// Deux syntaxes possibles
	// catch(Bureaucrat::GradeTooHighException & e)
	// {
	// 	std::cerr << RED << "Exception : couldn't create a bureaucrate :" << e.what() << RESET << std::endl;
	// }
	// catch(Bureaucrat::GradeTooLowException & e)
	// {
	// 	std::cerr << RED << "Exception : couldn't create a bureaucrate :" << e.what() << RESET << std::endl;		
	// }
}

int main(void)
{
	std::cout << std::endl << BOLD << "*** Bureaucrat test with default constructor ***" << RESET << std::endl;
	{
		Bureaucrat	b;
		std::cout << "Default bureaucrat is: " << b << std::endl;
	}
	std::cout << std::endl << BOLD << "*** Bureaucrat test with name and grade initialization constructor ***" << RESET << std::endl;
	{
		// should succeed
		TestBureaucrat("Gagao", 15);
		TestBureaucrat("Momo", 70);
		// should fail
		TestBureaucrat("Bibi", -8);
		TestBureaucrat("Jolie", 180);
	}
	std::cout << std::endl << BOLD << "*** Bureaucrat test copy constructor ***" << RESET << std::endl;
	{
		Bureaucrat b("Jolie", 45);
		std::cout << " Bureaucrat is " << b << std::endl;
		Bureaucrat bCopy(b);
		std::cout << " Bureaucrat is " << bCopy << std::endl;

	}
	std::cout << std::endl << BOLD << "*** Bureaucrat test copy assignement ***" << RESET << std::endl;
	{
		Bureaucrat b("Mimi", 64);
		Bureaucrat bCopy;
		std::cout << " Bureaucrat is " << b << std::endl;
		std::cout << " Bureaucrat is " << bCopy << std::endl;
		bCopy = b;
		std::cout << " Bureaucrat is " << bCopy << std::endl;
	}
	std::cout << std::endl << BOLD << "*** Bureaucrat test with incrementation and decrementation ***" << RESET << std::endl;
	{	
		std::cout << "-- Testing limite min --" << std::endl;
		Bureaucrat bMax("Momo", 147);
		try 
		{
			std::cout << "Decrementing the grade by 1, grade should be : " << bMax.getGrade() + 1 << std::endl;
			bMax.decrementeGrade();
			std::cout << bMax << std::endl;
			std::cout << "Decrementing the grade by 1, grade should be : " << bMax.getGrade() + 1 << std::endl;
			bMax.decrementeGrade();
			std::cout << bMax << std::endl;
			std::cout << "Decrementing the grade by 1, grade should be : " << bMax.getGrade() + 1 << std::endl;
			bMax.decrementeGrade();
			std::cout << bMax << std::endl;
			std::cout << "Decrementing the grade by 1, grade should be : " << bMax.getGrade() + 1 << std::endl;
			bMax.decrementeGrade();
			std::cout << bMax << std::endl;
			std::cout << "Decrementing the grade by 1, grade should be : " << bMax.getGrade() + 1 << std::endl;
			bMax.decrementeGrade();
			std::cout << bMax << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << "Exception : " << e.what() << RESET << std::endl;
		}
	
		std::cout << "-- Testing limite max --" << std::endl;
		Bureaucrat bMin("Momo", 2);
		try 
		{
			std::cout << "Incrementing the grade by 1, grade should be : " << bMin.getGrade() - 1 << std::endl;
			bMin.incrementeGrade();
			std::cout << bMin << std::endl;
			std::cout << "Incrementing the grade by 1, grade should be : " << bMin.getGrade() - 1 << std::endl;
			bMin.incrementeGrade();
			std::cout << bMin << std::endl;
			std::cout << "Incrementing the grade by 1, grade should be : " << bMin.getGrade() - 1 << std::endl;
			bMin.incrementeGrade();
			std::cout << bMin << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << "Exception : " << e.what() << RESET << std::endl;
		}
	
	}

	return 0;
}