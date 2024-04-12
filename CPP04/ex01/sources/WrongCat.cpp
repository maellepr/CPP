#include "../include/WrongCat.hpp"

/**** Default constructor ****/
WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << ORANGE << ITAL << "WrongCat class : " << RESET << "default constructor called" << std::endl;
	return ;
}

/**** Constructor taking the name as parameter ****/
WrongCat::WrongCat(std::string const type) : WrongAnimal()
{
	this->_type = type;
	std::cout << ORANGE << ITAL << "WrongCat class : " << RESET << "constructor called with type initialized" << std::endl;
	return ;
}

/**** Copy constructor ****/
WrongCat::WrongCat(WrongCat const & src) 
{
	std::cout << ORANGE << ITAL << "WrongCat class : " << RESET << "copy constructor called" << std::endl;
	this->_type = src.getType();
	return ;
}

/**** Destructor ****/
WrongCat::~WrongCat(void)
{
	std::cout << ORANGE << ITAL << "WrongCat class : " << RESET << "Destructor called" << std::endl;
	return ;
}

/**** Assignement operator ****/
WrongCat &	WrongCat::operator=(WrongCat const & src)
{
	std::cout << "WrongCat class : copy assignment operator called" << std::endl;
	if (this != &src) {
		this->_type = src.getType();
	}
	return (*this);
}

/**** Other members functions ****/
void	WrongCat::makeSound(void) const 
{
	std::string	color;

	if (this->_type == "WrongCat")
		color = ORANGE;
	else if (this->_type == "WrongAnimal")
		color = RED;

	std::cout  << color << BOLD << this->_type << RESET << BOLD << " : WrRiAouUu !" << RESET << std::endl;
}