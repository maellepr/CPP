#include "../include/AMateria.hpp"

/**** Default constructor ****/
AMateria::AMateria(void)
{
	std::cout << PINK << ITAL << "Materia class : " << RESET << "default constructor called"  << std::endl;
	return ;
}

/**** Copy constructor ****/
AMateria::AMateria(AMateria const & materia)
{
	//a completer
	std::cout << PINK << ITAL << "Materia class : " << RESET << "copy constructor called" << std::endl;
	return ;
}


/**** Destructor ****/
AMateria::~AMateria(void)
{
	std::cout << PINK << ITAL << "Materia class : " << RESET << "destructor called" << std::endl;
	return ;
}

/**** Assignement operator ****/
AMateria &	AMateria::operator=(AMateria const & materia)
{
	std::cout << "Materia class : copy assignment operator called" << std::endl;
	if (this != &materia) {
		this->_type = materia._type;
	}
	return (*this);
}

std::string const &	AMateria::getType() const
{
	//retourne le materia type
	return this->_type;
}