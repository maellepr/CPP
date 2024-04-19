#include "../include/Form.hpp"

/**** Default constructor ****/
Form::Form(void): 
_name("no name"),
_signed(false),
_gradeRequiredToSign(Bureaucrat::_lowestGrade),
_gradeRequiredToExecute(Bureaucrat::_lowestGrade) 
{
	std::cout << GREEN << ITAL << "Form class : " << RESET << "default constructor called" << std::endl;
	return ;
}

/**** Constructor with name and signed initialization ****/
Form::Form(const std::string name, const int to_sign, const int to_exec): 
_name(name),
_signed(false),
_gradeRequiredToSign(to_sign),
_gradeRequiredToExecute(to_exec)
{
	std::cout << GREEN << ITAL << "Form class : " << RESET << "constructor called with name and grade initialization" << std::endl;
	if (to_sign < Bureaucrat::_highestGrade || to_exec < Bureaucrat::_highestGrade)
		throw Bureaucrat::GradeTooHighException();
	else if (to_sign > Bureaucrat::_lowestGrade || to_exec > Bureaucrat::_lowestGrade)
		throw Bureaucrat::GradeTooLowException();
	return ;
}

/**** Copy constructor ****/
Form::Form(Form const & src):
_name(src._name),
_signed(src._signed),
_gradeRequiredToSign(src._gradeRequiredToSign),
_gradeRequiredToExecute(src._gradeRequiredToExecute)
{
	std::cout << GREEN << ITAL << "Form class : " << RESET << "copy constructor called" << std::endl;
	return ;
}

/**** Destructor ****/
Form::~Form(void)
{
	std::cout << GREEN << ITAL << "Form class : " << RESET << "destructor called" << std::endl;
	return ;
}

/**** Assignement operator ****/
Form &	Form::operator=(Form const & src)
{
	std::cout << "Form class : copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_signed = src._signed;
	}
	return (*this);
}

/**** << operator ****/
std::ostream &	operator<<(std::ostream & os, Form const & src)
{
	os << BOLD << src.getName() << RESET << " [" 
	<< BOLD << (src.isSigned() ? "signed" : "unsigned" ) << RESET 
	<< ", to sign:" << BOLD << src.getGradeRequiredToSign() << RESET
	<< ", to execute:" << BOLD << src.getGradeRequiredToExecute() << RESET << "]";
	return os;
}

/**** Getter ****/
const std::string	Form::getName() const
{
	return this->_name;
}

int	Form::getGradeRequiredToSign(void) const
{
	return this->_gradeRequiredToSign;
}

int	Form::getGradeRequiredToExecute(void) const
{
	return this->_gradeRequiredToExecute;
}

/*** Exceptions ****/
const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("grade too high !");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("grade too low !");
}

const char *Form::AlreadySigned::what(void) const throw()
{
	return ("already signed !");
}

/**** Other members functions ****/
bool	Form::isSigned() const
{
	return this->_signed;
}

void	Form::beSigned(Bureaucrat const &b)
{
	if (this->_signed)
		throw Form::AlreadySigned();
	if (b.getGrade() <= this->_gradeRequiredToSign)
	{
		this->_signed = true;
	}
	else
		throw Form::GradeTooLowException();
	return 
;}