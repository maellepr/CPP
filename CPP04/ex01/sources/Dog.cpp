#include "../include/Dog.hpp"

/**** Default constructor ****/
Dog::Dog(void) : Animal("Dog")
{
	std::cout << YELLOW << ITAL << "Dog class : " << RESET << "default constructor called" << std::endl;
	this->_brain = new Brain();
	return ;
}

/**** Copy constructor ****/
Dog::Dog(Dog const & dog) : Animal(dog)
{
	std::cout << YELLOW << ITAL << "Dog class : " << RESET << "copy constructor called" << std::endl;
	this->_brain = new Brain(*(dog._brain));
	this->_type = dog._type;
	return ;
}

/**** Destructor ****/
Dog::~Dog(void)
{
	std::cout << YELLOW << ITAL << "Dog class : " << RESET "Destructor called" << std::endl;
	delete this->_brain;
	return ;
}

/**** Assignement operator ****/
Dog &	Dog::operator=(Dog const & dog)
{
	std::cout << YELLOW << ITAL << "Dog class : " << RESET << "copy assignment operator called" << std::endl;
	if (this != &dog)
	{
		this->_type = dog._type;
		if (this->_brain != NULL)
			delete (this->_brain);
		this->_brain = new Brain(*dog._brain);
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

	std::cout << color << BOLD << this->_type << RESET << BOLD << " : Woaf woaf !" << RESET << std::endl;
}

Brain *	Dog::getBrain(void) const
{
	return this->_brain;
}
