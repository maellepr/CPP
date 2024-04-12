#include "../include/Brain.hpp"

/**** Default constructor ****/
Brain::Brain(void) :
{
	std::cout << GREEN << ITAL << "Brain class : " << RESET << "default constructor called" << std::endl;
	return ;
}

/**** Constructor taking the name as parameter ****/
Brain::Brain(std::string const type) : 
{
	// this->_type = type;
	std::cout << GREEN << ITAL << "Brain class : " << RESET << "constructor called with type initialized" << std::endl;
	return ;
}

/**** Copy constructor ****/
Brain::Brain(Brain const & src) 
{
	std::cout << GREEN << ITAL << "Brain class : " << RESET << "copy constructor called" << std::endl;
	// this->_type = src.getType();
	return ;
}

/**** Destructor ****/
Brain::~Brain(void)
{
	std::cout << GREEN << ITAL << "Brain class : " << RESET "Destructor called" << std::endl;
	return ;
}

/**** Assignement operator ****/
Brain &	Brain::operator=(Brain const & src)
{
	std::cout << "Brain class : copy assignment operator called" << std::endl;
	if (this != &src) {
		// this->_type = src.getType();
	}
	return (*this);
}