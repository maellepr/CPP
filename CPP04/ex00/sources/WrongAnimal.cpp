#include "../include/WrongAnimal.hpp"

/**** Default constructor ****/
WrongAnimal::WrongAnimal(void)
{
	_type = "WrongAnimal";
	std::cout << "WrongAnimal class : default constructor called" << std::endl;
	return ;
}

/**** Constructor taking the name as parameter ****/
WrongAnimal::WrongAnimal(std::string const type) : _type(type)
{

	std::cout << "WrongAnimal class : constructor called with type initialized" << std::endl;
	return ;
}

/**** Copy constructor ****/
WrongAnimal::WrongAnimal(WrongAnimal const & src) 
{
	std::cout << "WrongAnimal class : copy constructor called" << std::endl;
	this->_type = src.getType();
	return ;
}

/**** Destructor ****/
WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal class : destructor called" << std::endl;
	return ;
}

/**** Assignement operator ****/
WrongAnimal &	WrongAnimal::operator=(WrongAnimal const & src)
{
	std::cout << "WrongAnimal class : copy assignment operator called" << std::endl;
	if (this != &src) {
		this->_type = src.getType();
	}
	return (*this);
}

/**** Getter ****/
std::string const & WrongAnimal::getType(void) const 
{
	return this->_type;
}

/**** Other members functions ****/
void	WrongAnimal::makeSound(void) const 
{
	std::cout << this->_type << " : Random WrongAnimal sound" << std::endl;
}