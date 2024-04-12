#include "../include/Cure.hpp"

/**** Default constructor ****/
Cure::Cure(void) : AMateria("cure")
{
	std::cout << PINK << ITAL << "Cure class : " << RESET << "default constructor called"  << std::endl;
	return ;
}

/**** Copy constructor ****/
Cure::Cure(Cure const & cure) : AMateria()
{
	this->_type = cure._type;	
	std::cout << PINK << ITAL << "Cure class : " << RESET << "copy constructor called" << std::endl;
	return ;
}


/**** Destructor ****/
Cure::~Cure(void)
{
	std::cout << PINK << ITAL << "Cure class : " << RESET << "destructor called" << std::endl;
	return ;
}

/**** Assignement operator ****/
Cure &	Cure::operator=(Cure const & cure)
{
	std::cout << "Cure class : copy assignment operator called" << std::endl;
	if (this != &cure) {
		this->_type = cure._type;
	}
	return (*this);
}

Cure* Cure::clone(void) const
{
	return new Cure();
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl; 
}
