#include "../include/Dog.hpp"

/**** Default constructor ****/
Dog::Dog(void) : Animal("Dog"), _brain(new Brain)
{
	std::cout << YELLOW << ITAL << "Dog class : " << RESET "default constructor called" << std::endl;
	return ;
}

/**** Constructor taking the name as parameter ****/
Dog::Dog(std::string const type) : Animal()
{
	this->_type = type;
	std::cout << YELLOW << ITAL << "Dog class : " << RESET << "constructor called with type initialized" << std::endl;
	return ;
}

/**** Copy constructor ****/
Dog::Dog(Dog const & src)
{
	std::cout << YELLOW << ITAL << "Dog class : " << RESET << "copy constructor called" << std::endl;
	this->_type = src.getType();
	return ;
}

/**** Destructor ****/
Dog::~Dog(void)
{
	std::cout << YELLOW << ITAL << "Dog class : " << RESET << "destructor called" << std::endl;
	delete	this->_brain;
	return ;
}

/**** Assignement operator ****/
Dog &	Dog::operator=(Dog const & src)
{
	std::cout << "Dog class : copy assignment operator called" << std::endl;
	if (this != &src) {
		this->_type = src.getType();
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