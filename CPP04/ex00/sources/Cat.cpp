#include "../include/Cat.hpp"

/**** Default constructor ****/
Cat::Cat(void) : Animal("Cat")
{
	std::cout << GREEN << ITAL << "Cat class : " << RESET << "default constructor called" << std::endl;
	return ;
}

/**** Copy constructor ****/
Cat::Cat(Cat const & src) : Animal()
{
	this->_type = src._type;
	std::cout << GREEN << ITAL << "Cat class : " << RESET << "copy constructor called" << std::endl;
	return ;
}

/**** Destructor ****/
Cat::~Cat(void)
{
	std::cout << GREEN << ITAL << "Cat class : " << RESET "Destructor called" << std::endl;
	return ;
}

/**** Assignement operator ****/
Cat &	Cat::operator=(Cat const & src)
{
	std::cout << "Cat class : copy assignment operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

/**** Other members functions ****/
void	Cat::makeSound(void) const
{
	std::string	color;

	if (this->_type == "Cat")
		color = GREEN;
	else if (this->_type == "Dog")
		color = YELLOW;
	else if (this->_type == "Animal")
		color = PINK;

	std::cout << color << BOLD << this->_type << RESET << BOLD << " : Miaouuu !" << RESET << std::endl;
}