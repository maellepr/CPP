#include "../include/Animal.hpp"

/**** Default constructor ****/
Animal::Animal(void)
{
	_type = "Animal";
	std::cout << "Animal class : default constructor called" << std::endl;
	return ;
}

/**** Constructor taking the name as parameter ****/
Animal::Animal(std::string const type) : _type(type)
{

	std::cout << "Animal class : constructor called with type initialized" << std::endl;
	return ;
}

/**** Copy constructor ****/
Animal::Animal(Animal const & src) 
{
	std::cout << "Animal class : copy constructor called" << std::endl;
	this->_type = src.getType();
	return ;
}

/**** Destructor ****/
Animal::~Animal(void)
{
	std::cout << "Animal class : destructor called" << std::endl;
	return ;
}

/**** Assignement operator ****/
Animal &	Animal::operator=(Animal const & src)
{
	std::cout << "Animal class : copy assignment operator called" << std::endl;
	if (this != &src) {
		this->_type = src.getType();
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
	std::cout << this->_type << " : Random animal sound" << std::endl;
}