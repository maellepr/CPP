#include "../include/Character.hpp"

/**** Default constructor ****/
Character::Character(void) : _name("characterName")
{
	this->_setEmptyInventory();
	// std::cout << GREEN << ITAL << "Character class : " << RESET << "default constructor called"  << std::endl;
	return ;
}

/**** Constructor with name initialized*/
Character::Character(std::string const name) : _name(name)
{
	this->_setEmptyInventory();
	// std::cout << GREEN << ITAL << "Character class : " << RESET << "constructor with name " << this->_name << " initializion called" << std::endl;
	return ;
}

/**** Copy constructor ****/
Character::Character(Character const & character)
{
	this->_name = character._name;
	for (int i = 0; i < this->_inventorySize; i++)
	{
		if (character._inventory[i])
			this->_inventory[i] = character._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	// std::cout << GREEN << ITAL << "Character class : " << RESET << "copy constructor called" << std::endl;
	return ;
}

/**** Destructor ****/
Character::~Character(void)
{
	this->_deleteInventory();
	// std::cout << GREEN << ITAL << "Character class : " << RESET << "destructor called" << std::endl;
	return ;
}

/**** Assignement operator ****/
Character &	Character::operator=(Character const & character)
{
	// std::cout << "Materia class : copy assignment operator called" << std::endl;
	if (this != &character) 
	{		
		this->_name = character._name;
		for (int i = 0; i < this->_inventorySize; i++)
		{
			if (this->_inventory[i])
			{
				delete this->_inventory[i];
				this->_inventory[i] = NULL;
			}
			if (character._inventory[i])
				this->_inventory[i] = character._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	return (*this);
}

std::string const &	Character::getName(void) const
{
	return this->_name;
}

void	Character::setname(std::string const name)
{
	this->_name = name;
	return ;
}


void	Character::equip(AMateria* m)
{
	if (!m)
	{
		// std::cout << this->_name << " can't equip, empty materia" << std::endl;
		return ;
	}
	for (int i = 0; i < this->_inventorySize; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			// std::cout << "The materia " << m->getType() << " has been saved in the inventory[" 
			// << i << "] of the Character named " << this->_name << " ! " << std::endl;
			return ;
		}
	}
	// std::cout << "The materia " << m->getType() << " couldn't be saved because the inventory of " 
	// << this->_name << " is full" << std::endl;
	return ;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= this->_inventorySize)
	{
		std::cout << this->_name << " can't unequip this index[" << idx 
		<< "], index has to be a number between 0 and 3" << std::endl;
		return ;
	}
	if (this->_inventory[idx] == NULL)
	{
		std::cout << this->_name << " can't unequip this index[" << idx 
		<< "], it's already empty !" << std::endl;
		return ;		
	}
	std::cout << this->_name << " has unequiped his index[" << idx 
	<< "] of the materia " << this->_inventory[idx]->getType() << std::endl;
	this->_inventory[idx] = NULL;
	return ;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= this->_inventorySize)
	{
		std::cout << this->_name << " can't use the materia at index[" << idx 
		<< "], this index number is not valid, it has to be between 0 and 3" << std::endl;
		return ;
	}
	if (this->_inventory[idx] == NULL)
	{
		std::cout << this->_name << " can't use this index[" << idx 
		<< "] materia, there's none here" << std::endl;
		return ;
	}
	// std::cout << this->_name << " is using " << this->_inventory[idx]->getType();
	this->_inventory[idx]->use(target);
	return ;
}

void	Character::displayInventory(void) const
{
	std::cout << this->_name << "'s inventory :" << std::endl;
	for (int i = 0; i < this->_inventorySize; i++)
	{
		if (this->_inventory[i] == NULL)
			std::cout << "index [" << i << "] is empty" << std::endl;
		else
			std::cout << "index [" << i << "] : " << this->_inventory[i]->getType() << std::endl;
	}
	return ;
}

void	Character::_setEmptyInventory(void)
{
	for (int i = 0; i < this->_inventorySize; i++)
		this->_inventory[i] = NULL;
	return ;
}

void	Character::_deleteInventory(void)
{
	for (int i = 0; i < this->_inventorySize; i++)
	{
		if (this->_inventory[i] != NULL)
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
	return ;
}