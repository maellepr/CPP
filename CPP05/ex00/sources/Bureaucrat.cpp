#include "../include/Bureaucrat.hpp"

/**** Default constructor ****/
Bureaucrat::Bureaucrat(void): _name("GenericName"), _grade(this->_lowestGrade)
{
	std::cout << YELLOW << ITAL << "Bureaucrat class : " << RESET << "default constructor called" << std::endl;
	return ;
}

/**** Constructor with name and grade initialization ****/
Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name)
{
	std::cout << YELLOW << ITAL << "Bureaucrat class : " << RESET << "constructor called with name and grade initialization" << std::endl;
	if (grade < this->_highestGrade)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > this->_lowestGrade)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
	return ;
}

/**** Copy constructor ****/
Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name), _grade(src._grade)
{
	std::cout << YELLOW << ITAL << "Bureaucrat class : " << RESET << "copy constructor called" << std::endl;
	return ;
}

/**** Destructor ****/
Bureaucrat::~Bureaucrat(void)
{
	std::cout << YELLOW << ITAL << "Bureaucrat class : " << RESET << "destructor called" << std::endl;
	return ;
}

/**** Assignement operator ****/
Bureaucrat &	Bureaucrat::operator=(Bureaucrat const & src)
{
	std::cout << "Bureaucrat class : copy assignment operator called" << std::endl;
	if (this != &src)
	{
		// this->_name = src._name;
		this->_grade = src._grade;
	}
	return (*this);
}

/**** << operator ****/
std::ostream &	operator<<(std::ostream & os, Bureaucrat const & src)
{
	os << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
	return os;
}

/**** Getter ****/
const std::string	Bureaucrat::getName() const
{
	return this->_name;
}

unsigned int	Bureaucrat::getGrade() const
{
	return this->_grade;
}

/*** Exceptions ****/
const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high !");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low !");
}

/**** Other members functions ****/
void	Bureaucrat::incrementeGrade(void)
{
	if (this->_grade > this->_highestGrade)
		this->_grade -= 1;
	else
		std::cout << "Can't incremente, the grade is already at the highest (1)" << std::endl;
	return ;
}

void	Bureaucrat::decrementeGrade(void)
{
	if (this->_grade < this->_lowestGrade)
		this->_grade += 1;
	else
		std::cout << "Can't decremente, the grade is already at the lowest (150)" << std::endl;
	return ;
}