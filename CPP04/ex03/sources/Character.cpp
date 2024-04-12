#include "../include/Character.hpp"

/**** Default constructor ****/
Character::Character(void)
{
	std::cout << YELLOW << ITAL << "Character class : " << RESET << "default constructor called"  << std::endl;
	return ;
}

/**** Copy constructor ****/
Character::Character(Character const & character)
{
	//a completer
	std::cout << PINK << ITAL << "Materia class : " << RESET << "copy constructor called" << std::endl;
	return ;
}

/**** Destructor ****/
Character::~Character(void)
{
	std::cout << YELLOW << ITAL << "Character class : " << RESET << "destructor called" << std::endl;
	return ;
}

/**** Assignement operator ****/
Character &	Character::operator=(Character const & character)
{
	std::cout << "Materia class : copy assignment operator called" << std::endl;
	if (this != &character) 
	{
		this->_name = character._name;
	}
	return (*this);
}
