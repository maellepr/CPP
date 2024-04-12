#include "../include/MateriaSource.hpp"

/**** Default constructor ****/
MateriaSource::MateriaSource(void)
{
	std::cout << YELLOW << ITAL << "MateriaSource class : " << RESET << "default constructor called"  << std::endl;
	return ;
}

/**** Copy constructor ****/
MateriaSource::MateriaSource(MateriaSource const & MateriaSource)
{
	//a completer
	std::cout << PINK << ITAL << "Materia class : " << RESET << "copy constructor called" << std::endl;
	return ;
}

/**** Destructor ****/
MateriaSource::~MateriaSource(void)
{
	std::cout << YELLOW << ITAL << "MateriaSource class : " << RESET << "destructor called" << std::endl;
	return ;
}

/**** Assignement operator ****/
MateriaSource &	MateriaSource::operator=(MateriaSource const & materiaSource)
{
	std::cout << "Materia class : copy assignment operator called" << std::endl;
	if (this != &materiaSource) 
	{
		// this->_name = materiaSource._name;
	}
	return (*this);
}