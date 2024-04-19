#include "../include/RobotomyRequestForm.hpp"

/*** Default constructor ****/
RobotomyRequestForm::RobotomyRequestForm(void): 
AForm("RobotomyRequestForm", this->_gradeRequiredToSign, this->_gradeRequiredToExecute), 
_target("")
{
	std::cout << LBLUE1 << ITAL << "RobotomyRequestForm class : " << RESET << "default constructor called" << std::endl;
	return ;
}

/**** Constructor with target initialization ****/
RobotomyRequestForm::RobotomyRequestForm(std::string target):
AForm("RobotomyRequestForm", this->_gradeRequiredToSign, this->_gradeRequiredToExecute),
_target(target)
{
	std::cout << LBLUE1 << ITAL << "RobotomyRequestForm class : " << RESET << "constructor called with target initialization" << std::endl;

}

/**** Copy constructor *****/
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src):
AForm(src._target, src._gradeRequiredToSign, src._gradeRequiredToExecute)
{
	std::cout << LBLUE1 << ITAL << "RobotomyRequestForm class : " << RESET << "copy constructor called" << std::endl;
	this->_target = src._target;
}

/**** Destructor ****/
RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << LBLUE1 << ITAL << "RobotomyRequestForm class : " << RESET << "destructor called" << std::endl;
}

/**** Assignement Operator ****/
RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & src)
{
	std::cout << "Shrubbery class : copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_target = src._target;
	}
	return (*this);	
}

/**** Other Functions ****/
void	RobotomyRequestForm::doExecution(void) const
{
	std::cout << "VvvvzzZZZzzzzzz vvvvzzzzZZzzzZZzz" << std::endl;
	// std::srand((unsigned int)time(0));
	if (std::rand() % 2 == 1)
		std::cout << this->_target << " has been robotomized successfully !" << std::endl;
	else
		std::cout << "The robotomy failed..." << std::endl;
	return ;
}