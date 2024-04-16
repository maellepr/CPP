#include "../include/Cure.hpp"

/**** Default constructor ****/
Cure::Cure(void) : AMateria("cure")
{
	// std::cout << LBLUE2 << ITAL << "Cure class : " << RESET << "default constructor called"  << std::endl;
	return ;
}

/**** Copy constructor ****/
Cure::Cure(Cure const & cure) : AMateria()
{
	this->_type = cure._type;	
	// std::cout << LBLUE2 << ITAL << "Cure class : " << RESET << "copy constructor called" << std::endl;
	return ;
}


/**** Destructor ****/
Cure::~Cure(void)
{
	// std::cout << LBLUE2 << ITAL << "Cure class : " << RESET << "destructor called" << std::endl;
	return ;
}

/**** Assignement operator ****/
Cure &	Cure::operator=(Cure const & cure)
{
	// std::cout << "Cure class : copy assignment operator called" << std::endl;
	if (this != &cure) {
		this->_type = cure._type;
	}
	return (*this);
}

Cure* Cure::clone(void) const
{
	// std::cout << "A AMateria " << LBLUE2 << BOLD << "Cure" << RESET << " has been cloned !" << std::endl;
	return new Cure();
}

void Cure::use(ICharacter& target)
{
	std::cout << /*LBLUE2 << BOLD <<*/ "* heals " << target.getName() << "'s wounds *" /*<< RESET*/ << std::endl; 
}
