#include "../include/PresidentialPardonForm.hpp"

/*** Default constructor ****/
PresidentialPardonForm::PresidentialPardonForm(void): 
AForm("PresidentialPardonForm", this->_gradeRequiredToSign, this->_gradeRequiredToExecute), 
_target("")
{
	std::cout << LBLUE2 << ITAL << "PresidentialPardonForm class : " << RESET << "default constructor called" << std::endl;
	return ;
}

/**** Constructor with target initialization ****/
PresidentialPardonForm::PresidentialPardonForm(std::string target):
AForm("PresidentialPardonForm", this->_gradeRequiredToSign, this->_gradeRequiredToExecute),
_target(target)
{
	std::cout << LBLUE2 << ITAL << "PresidentialPardonForm class : " << RESET << "constructor called with target initialization" << std::endl;

}

/**** Copy constructor *****/
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src):
AForm(src._target, src._gradeRequiredToSign, src._gradeRequiredToExecute)
{
	std::cout << LBLUE2 << ITAL << "PresidentialPardonForm class : " << RESET << "copy constructor called" << std::endl;
	this->_target = src._target;
}

/**** Destructor ****/
PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << LBLUE2 << ITAL << "PresidentialPardonForm class : " << RESET << "destructor called" << std::endl;
}

/**** Assignement Operator ****/
PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & src)
{
	std::cout << "Shrubbery class : copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_target = src._target;
	}
	return (*this);	
}

/**** Other Functions ****/
void	PresidentialPardonForm::doExecution(void) const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	return ;
}