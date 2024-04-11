#include "../include/Dog.hpp"

/**** Default constructor ****/
Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog class : default constructor called" << std::endl;
	return ;
}

/**** Constructor taking the name as parameter ****/
Dog::Dog(std::string const type) : Animal()
{
	this->_type = type;
	std::cout << "Dog class : constructor called with type initialized" << std::endl;
	return ;
}

/**** Copy constructor ****/
Dog::Dog(Dog const & src)
{
	std::cout << "Dog class : copy constructor called" << std::endl;
	this->_type = src.getType();
	return ;
}

/**** Destructor ****/
Dog::~Dog(void)
{
	std::cout << "Dog class : destructor called" << std::endl;
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
	std::cout << this->_type << " : Woaf woaf !" << std::endl;
}