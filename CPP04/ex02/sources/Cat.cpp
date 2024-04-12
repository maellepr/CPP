#include "../include/Cat.hpp"
#include "../include/Brain.hpp"

/**** Default constructor ****/
Cat::Cat(void) : AAnimal("Cat")
{
	std::cout << GREEN << ITAL << "Cat class : " << RESET << "default constructor called" << std::endl;
	this->_brain = new Brain();
	return ;
}

/**** Copy constructor ****/
Cat::Cat(Cat const & cat) : AAnimal(cat)
{
	std::cout << GREEN << ITAL << "Cat class : " << RESET << "copy constructor called" << std::endl;
	this->_brain = new Brain(*cat._brain);
	this->_type = cat._type;
	return ;
}

/**** Destructor ****/
Cat::~Cat(void)
{
	std::cout << GREEN << ITAL << "Cat class : " << RESET "Destructor called" << std::endl;
	delete this->_brain;
	return ;
}

/**** Assignement operator ****/
Cat &	Cat::operator=(Cat const & cat)
{
	std::cout << GREEN << ITAL << "Cat class : " << RESET << "copy assignment operator called" << std::endl;
	if (this != &cat)
	{
		this->_type = cat._type;
		if (this->_brain != NULL)
			delete (this->_brain);
		this->_brain = new Brain(*cat._brain);
	}
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

Brain *	Cat::getBrain(void) const
{
	return this->_brain;
}