#include "../include/Dog.hpp"

/**** Default constructor ****/
Dog::Dog(void) : Animal("Dog")
{
	std::cout << YELLOW << ITAL << "Dog class : " << RESET "default constructor called" << std::endl;
	return ;
}

/**** Copy constructor ****/
Dog::Dog(Dog const & src) : Animal()
{
	std::cout << YELLOW << ITAL << "Dog class : " << RESET << "copy constructor called" << std::endl;
	*this = src;
	return ;
}

/**** Destructor ****/
Dog::~Dog(void)
{
	std::cout << YELLOW << ITAL << "Dog class : " << RESET << "destructor called" << std::endl;
	return ;
}

/**** Assignement operator ****/
Dog &	Dog::operator=(Dog const & src)
{
	std::cout << "Dog class : copy assignment operator called" << std::endl;
	if (this != &src) {
		this->_type = src._type;
	}
	return (*this);
}

/**** Other members functions ****/
void	Dog::makeSound(void) const 
{
	std::string	color;

	if (this->_type == "Cat")
		color = GREEN;
	else if (this->_type == "Dog")
		color = YELLOW;
	else if (this->_type == "Animal")
		color = PINK;
	else
		color = GREEN;

	std::cout << color << BOLD << this->_type << RESET << BOLD << " : Woaf woaf !" << RESET << std::endl;
}