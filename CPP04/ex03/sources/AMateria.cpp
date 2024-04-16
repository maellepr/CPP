#include "../include/AMateria.hpp"

/**** Default constructor ****/
AMateria::AMateria(void)
{
	// std::cout << BLUE << ITAL << "Materia class : " << RESET << "default constructor called"  << std::endl;
	return ;
}

/**** Constructor with type initializion ****/
AMateria::AMateria(std::string const & type) : _type(type)
{
	// std::cout << BLUE << ITAL << "Materia class : " << RESET << "constructor with type initializion called" << std::endl;
}

/**** Copy constructor ****/
AMateria::AMateria(AMateria const &materia)
{
	(void)materia;
	// std::cout << BLUE << ITAL << "Materia class : " << RESET << "copy constructor called" << std::endl;
	return ;
}

/**** Destructor ****/
AMateria::~AMateria(void)
{
	// std::cout << BLUE << ITAL << "Materia class : " << RESET << "destructor called" << std::endl;
	return ;
}

/**** Assignement operator ****/
AMateria &	AMateria::operator=(AMateria const & materia)
{
	// std::cout << BLUE << ITAL << "Materia class : " << RESET << "copy assignment operator called" << std::endl;
	(void)materia;
	return (*this);
}

std::string const &	AMateria::getType() const
{
	return this->_type;
}

void	AMateria::use(ICharacter& target)
{
	std::cout << target.getName() << std::endl;
	return ;
}