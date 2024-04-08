#include "../include/ScavTrap.hpp"

/**** Default constructor ****/
ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	return ;
}

/**** Constructor taking the name as parameter ****/
ScavTrap::ScavTrap(std::string const name) : ClapTrap()
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;	
	std::cout << "ScavTrap constructor called with name initialized" << std::endl;
	return ;
}

/**** Copy constructor ****/
ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap()
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	// *this = src;// a changer peut etre
	this->_name = src.getName();
	this->_hitPoints = src.getHitPoints();
	this->_energyPoints = src.getEnergyPoints();
	this->_attackDamage = src.getAttackDamage();
	return ;
}

/**** Destructor ****/
ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap Destructor called" << std::endl;
	return ;
}

/**** Operator ****/
ScavTrap &	ScavTrap::operator=(ScavTrap const & src)
{
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	if (this != &src) {
		this->_name = src.getName();
		this->_hitPoints = src.getHitPoints();
		this->_energyPoints = src.getEnergyPoints();
		this->_attackDamage = src.getAttackDamage();
	}
	return (*this);
}
