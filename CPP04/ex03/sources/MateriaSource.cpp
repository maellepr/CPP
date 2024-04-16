#include "../include/MateriaSource.hpp"

/**** Default constructor ****/
MateriaSource::MateriaSource(void)
{
	this->_setEmptyInventory();
	// std::cout << PURPLE << ITAL << "MateriaSource class : " << RESET << "default constructor called"  << std::endl;
	return ;
}

/**** Copy constructor ****/
MateriaSource::MateriaSource(MateriaSource const & materiasource)
{
	for (int i = 0; i < _inventorySize; i++)
	{
		if (materiasource._savingInventory[i])
			_savingInventory[i] = materiasource._savingInventory[i]->clone();
		else
			_savingInventory[i] = NULL;
	}
	// std::cout << PURPLE << ITAL << "Materia class : " << RESET << "copy constructor called" << std::endl;
	return ;
}

/**** Destructor ****/
MateriaSource::~MateriaSource(void)
{
	this->_deleteInventory();
	// std::cout << PURPLE << ITAL << "MateriaSource class : " << RESET << "destructor called" << std::endl;
	return ;
}

/**** Assignement operator ****/
MateriaSource &	MateriaSource::operator=(MateriaSource const & materiasource)
{
	// std::cout << "Materia class : copy assignment operator called" << std::endl;
	if (this != &materiasource) 
	{
		for (int i = 0; i < _inventorySize; i++)
		{
			if (this->_savingInventory[i])
			{
				delete this->_savingInventory[i];
				this->_savingInventory[i] = NULL;
			}
			if (materiasource._savingInventory[i])
				this->_savingInventory[i] = materiasource._savingInventory[i]->clone();
			else
				this->_savingInventory[i] = NULL;
		}
	}
	return (*this);
}

void	MateriaSource::_setEmptyInventory(void)
{
	for (int i = 0; i < this->_inventorySize; i++)
		this->_savingInventory[i] = NULL;
	return ;
}

void	MateriaSource::_deleteInventory(void)
{
	for (int i = 0; i < this->_inventorySize; i++)
	{
		if (this->_savingInventory[i] != NULL)
		{
			delete this->_savingInventory[i];
			this->_savingInventory[i] = NULL;
		}
	}
	return ;
}

void	MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < this->_inventorySize; i++)
	{
		if (this->_savingInventory[i] == NULL)
		{
			this->_savingInventory[i] = m;
			// std::cout << "Materia " << m->getType() << " has been learned (in the saving inventory)" << std::endl;
			return ;
		}
	}
	// std::cout << "MateriaSource can't learn, saving inventory is full" << std::endl;
	return ;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	if (!type.size())
		return (0);
	for (int i = 0; i < this->_inventorySize; i++)
	{
		if (this->_savingInventory[i] && this->_savingInventory[i]->getType() == type)
		{
			// std::cout << "New Materia of type " << type << " created !" << std::endl;
			return (this->_savingInventory[i]->clone());
		}
	}
	// std::cout << "Materia " << type << " was not found in the saving inventory so it couldn't be created" << std::endl;
	return (0);
}