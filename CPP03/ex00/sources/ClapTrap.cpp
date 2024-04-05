#include "../include/ClapTrap.hpp"

/**** Default constructor ****/
ClapTrap::ClapTrap(void) : _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

/**** Constructor taking the name as parameter ****/
ClapTrap::ClapTrap(std::string const name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Constructor with name called" << std::endl;
	return ;
}

/**** Copy constructor ****/
ClapTrap::ClapTrap(ClapTrap const & src) 
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;// a changer peut etre
	return ;
}

/**** Destructor ****/
ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

/**** Operator ****/
ClapTrap &	ClapTrap::operator=(ClapTrap const & src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src) {
		this->_name = src.getName();
		this->_hitPoints = src.getHitPoints();
		this->_energyPoints = src.getEnergyPoints();
		this->_attackDamage = src.getAttackDamage();
	}
	return (*this);
}

/**** Getter ****/
std::string	ClapTrap::getName(void) const 
{
	return this->_name;
}

unsigned int	ClapTrap::getHitPoints(void) const
{
	return this->_hitPoints;
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return this->_energyPoints;
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return this->_attackDamage;
}

/**** Setter ****/
// void	ClapTrap::setName(std::string name) const
// {
// 	std::cout << "Setter setName called" << std::endl;
// 	return ;
// }

// void		setHitPoints(unsigned int hitPoint) const
// {
// 	return ;
// }

// void		setEnergyPoints(unsigned int energyPoints) const
// {
// 	return ;
// }

// void		setAttackDamage(unsigned int attackDamage) const
// {
// 	return ;
// }

void	ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints == 0)
	{
		std::cout << "No more energy points ! " << this->_name << " can't attack !" << std::endl;
		return ;
	}
	if (this->_hitPoints == 0)
	{
		std::cout << "No more hit points ! " << this->_name << " can't attack ! " << std::endl;
		return ;
	}
	if (this->_name == target)
		std::cout << target << " is attacking himself !" << std::endl;
	else
		std::cout << this->_name << " attack " << target << " !" << std::endl; 
	this->_energyPoints--;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << this->_name << " just lost " << amount << " hitpoints" << std::endl;
	this->_hitPoints -= amount;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << this->_name << " repaired himself of " << amount << " hitpoints" << std::endl;
	this->_hitPoints += amount;
	this->_energyPoints--;
	return ;
}



