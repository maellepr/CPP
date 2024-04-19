#include "../include/AForm.hpp"

/**** Default constructor ****/
AForm::AForm(void): 
_name("no name"),
_signed(false),
_gradeRequiredToSign(Bureaucrat::_lowestGrade),
_gradeRequiredToExecute(Bureaucrat::_lowestGrade) 
{
	std::cout << GREEN << ITAL << "AForm class : " << RESET << "default constructor called" << std::endl;
	return ;
}

/**** Constructor with name and signed initialization ****/
AForm::AForm(const std::string name, const int to_sign, const int to_exec): 
_name(name),
_signed(false),
_gradeRequiredToSign(to_sign),
_gradeRequiredToExecute(to_exec)
{
	std::cout << GREEN << ITAL << "AForm class : " << RESET << "constructor called with name and grade initialization" << std::endl;
	if (to_sign < Bureaucrat::_highestGrade || to_exec < Bureaucrat::_highestGrade)
		throw Bureaucrat::GradeTooHighException();
	else if (to_sign > Bureaucrat::_lowestGrade || to_exec > Bureaucrat::_lowestGrade)
		throw Bureaucrat::GradeTooLowException();
	return ;
}

/**** Copy constructor ****/
AForm::AForm(AForm const & src):
_name(src._name),
_signed(src._signed),
_gradeRequiredToSign(src._gradeRequiredToSign),
_gradeRequiredToExecute(src._gradeRequiredToExecute)
{
	std::cout << GREEN << ITAL << "AForm class : " << RESET << "copy constructor called" << std::endl;
	return ;
}

/**** Destructor ****/
AForm::~AForm(void)
{
	std::cout << GREEN << ITAL << "AForm class : " << RESET << "destructor called" << std::endl;
	return ;
}

/**** Assignement operator ****/
AForm &	AForm::operator=(AForm const & src)
{
	std::cout << "AForm class : copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_signed = src._signed;
	}
	return (*this);
}

/**** << operator ****/
std::ostream &	operator<<(std::ostream & os, AForm const & src)
{
	os << BOLD << src.getName() << RESET << " [" 
	<< BOLD << (src.isSigned() ? "signed" : "unsigned" ) << RESET 
	<< ", to sign:" << BOLD << src.getGradeRequiredToSign() << RESET
	<< ", to execute:" << BOLD << src.getGradeRequiredToExecute() << RESET << "]";
	return os;
}

/**** Getter ****/
const std::string	AForm::getName() const
{
	return this->_name;
}

int	AForm::getGradeRequiredToSign(void) const
{
	return this->_gradeRequiredToSign;
}

int	AForm::getGradeRequiredToExecute(void) const
{
	return this->_gradeRequiredToExecute;
}

/*** Exceptions ****/
const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("grade too high !");
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("grade too low !");
}

const char *AForm::AlreadySigned::what(void) const throw()
{
	return ("already signed !");
}

const char *AForm::NotSigned::what(void) const throw()
{
	return ("not signed !");
}

/**** Other members functions ****/
bool	AForm::isSigned() const
{
	return this->_signed;
}

void	AForm::beSigned(Bureaucrat const &b)
{
	if (this->_signed)
		throw AForm::AlreadySigned();
	if (b.getGrade() <= this->_gradeRequiredToSign)
	{
		this->_signed = true;
	}
	else
		throw AForm::GradeTooLowException();
	return 
;}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (!this->isSigned())
		throw AForm::NotSigned();
	else if (this->isSigned() && executor.getGrade() <= this->_gradeRequiredToExecute)
		this->doExecution();
	else
		throw AForm::GradeTooLowException();
	return ;
}