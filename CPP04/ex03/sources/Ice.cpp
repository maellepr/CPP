#include "../include/Ice.hpp"

/**** Default constructor ****/
Ice::Ice(void) : AMateria()
{
	std::cout << RED << ITAL << "Ice class : " << RESET << "default constructor called"  << std::endl;
	return ;
}

/**** Copy constructor ****/
Ice::Ice(Ice const & ice) : AMateria()
{
	this->_type = ice._type;
	std::cout << RED << ITAL << "Ice class : " << RESET << "copy constructor called" << std::endl;
	return ;
}


/**** Destructor ****/
Ice::~Ice(void)
{
	std::cout << RED << ITAL << "Ice class : " << RESET << "destructor called" << std::endl;
	return ;
}

/**** Assignement operator ****/
Ice &	Ice::operator=(Ice const & ice)
{
	std::cout << "Ice class : copy assignment operator called" << std::endl;
	if (this != &ice) {
		this->_type = ice._type;
	}
	return (*this);
}

Ice* Ice::clone(void) const
{
	return new Ice();
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << std::endl; 
}
