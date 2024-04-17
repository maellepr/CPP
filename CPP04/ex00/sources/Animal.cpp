#include "../include/Animal.hpp"

/**** Default constructor ****/
Animal::Animal(void)
{
	_type = "Animal";
	std::cout << PINK << ITAL << "Animal class : " << RESET << "default constructor called"  << std::endl;
	return ;
}

/**** Constructor taking the name as parameter ****/
Animal::Animal(std::string const type) : _type(type)
{

	std::cout << PINK << ITAL << "Animal class : " << RESET << "constructor called with type initialized" << std::endl;
	return ;
}

/**** Copy constructor ****/
Animal::Animal(Animal const & src) 
{
	std::cout << PINK << ITAL << "Animal class : " << RESET << "copy constructor called" << std::endl;
	this->_type = src._type;
	return ;
}

/**** Destructor ****/
Animal::~Animal(void)
{
	std::cout << PINK << ITAL << "Animal class : " << RESET << "destructor called" << std::endl;
	return ;
}

/**** Assignement operator ****/
Animal &	Animal::operator=(Animal const & src)
{
	std::cout << "Animal class : copy assignment operator called" << std::endl;
	if (this != &src) {
		this->_type = src._type;
	}
	return (*this);
}

/**** Getter ****/
std::string const & Animal::getType(void) const 
{
	return this->_type;
}

/**** Other members functions ****/
void	Animal::makeSound(void) const 
{
	std::string	color;

	if (this->_type == "Cat")
		color = GREEN;
	else if (this->_type == "Dog")
		color = YELLOW;
	else if (this->_type == "Animal")
		color = PINK;

	std::cout << BOLD << color << this->_type << RESET << BOLD << " : Random animal sound..." << RESET << std::endl;
}