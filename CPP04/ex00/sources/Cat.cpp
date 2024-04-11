#include "../include/Cat.hpp"

/**** Default constructor ****/
Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat class : default constructor called" << std::endl;
	return ;
}

/**** Constructor taking the name as parameter ****/
Cat::Cat(std::string const type) : Animal()
{
	this->_type = type;
	std::cout << "Cat class : constructor called with type initialized" << std::endl;
	return ;
}

/**** Copy constructor ****/
Cat::Cat(Cat const & src) 
{
	std::cout << "Cat class : copy constructor called" << std::endl;
	this->_type = src.getType();
	return ;
}

/**** Destructor ****/
Cat::~Cat(void)
{
	std::cout << "Cat class : Destructor called" << std::endl;
	return ;
}

/**** Assignement operator ****/
Cat &	Cat::operator=(Cat const & src)
{
	std::cout << "Cat class : copy assignment operator called" << std::endl;
	if (this != &src) {
		this->_type = src.getType();
	}
	return (*this);
}

/**** Other members functions ****/
void	Cat::makeSound(void) const 
{
	std::cout << this->_type << " : Miaouuu !" << std::endl;
}