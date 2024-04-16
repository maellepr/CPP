#include "../include/Ice.hpp"

/**** Default constructor ****/
Ice::Ice(void) : AMateria("ice")
{
	// std::cout << LBLUE1 << ITAL << "Ice class : " << RESET << "default constructor called"  << std::endl;
	return ;
}

/**** Copy constructor ****/
Ice::Ice(Ice const & ice) : AMateria()
{
	this->_type = ice._type;
	// std::cout << LBLUE1 << ITAL << "Ice class : " << RESET << "copy constructor called" << std::endl;
	return ;
}


/**** Destructor ****/
Ice::~Ice(void)
{
	// std::cout << LBLUE1 << ITAL << "Ice class : " << RESET << "destructor called" << std::endl;
	return ;
}

/**** Assignement operator ****/
Ice &	Ice::operator=(Ice const & ice)
{
	// std::cout << LBLUE1 << ITAL << "Ice class : copy assignment operator called" << RESET << std::endl;
	if (this != &ice) {
		this->_type = ice._type;
	}
	return (*this);
}

Ice* Ice::clone(void) const
{
	// std::cout << "A AMateria " << LBLUE1 << BOLD << "Ice" << RESET << " has been cloned !" << std::endl;   
	return new Ice();
}

void Ice::use(ICharacter& target)
{
	std::cout << /*BOLD << LBLUE1 <<*/ "* shoots an ice bolt at " << target.getName() << " *" << /*RESET <<*/ std::endl; 
}
