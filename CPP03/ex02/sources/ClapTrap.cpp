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
	std::cout << "Constructor called with name initialized" << std::endl;
	return ;
}

/**** Copy constructor ****/
ClapTrap::ClapTrap(ClapTrap const & src) 
{
	std::cout << "Copy constructor called" << std::endl;
	// *this = src;// a changer peut etre
	this->_name = src.getName();
	this->_hitPoints = src.getHitPoints();
	this->_energyPoints = src.getEnergyPoints();
	this->_attackDamage = src.getAttackDamage();
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
	std::string color;
	std::string color2;

	color = getColor(this->_name);
	color2 = getColor(target);

	if (this->_energyPoints == 0)
	{
		std::cout << "No more energy points ! " << color << "\e[1m" << "\e[3m" << this->_name << "\e[0m"  << " can't attack !"<< std::endl;
		return ;
	}
	if (this->_hitPoints == 0)
	{
		std::cout << "No more hit points ! " << color << "\e[1m" << "\e[3m" << this->_name << "\e[0m" << " can't attack ! " << std::endl;
		return ;
	}
	if (this->_name == target)
		std::cout << color2 << "\e[1m" << "\e[3m" << target << "\e[0m" << " is attacking himself !" << std::endl;
	else
		std::cout << color << "\e[1m" << "\e[3m" << this->_name << "\e[0m" << " attack " << target << " !" << std::endl; 
	this->_energyPoints--;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::string color;

	color = getColor(this->_name);

	if (this->_hitPoints <= 0)
		std::cout << color << "\e[1m" << "\e[3m"  << this->_name <<  "\e[0m" << " can't take any more damage !" << std::endl;		
	else if (this->_hitPoints <= amount)
	{
		std::cout << color << "\e[1m" << "\e[3m" << this->_name << "\e[0m" << " take " << amount << " damage and is dead" << std::endl;		
		this->_hitPoints = 0;
	}
	else
	{
		std::cout << color << "\e[1m" << "\e[3m" << this->_name <<  "\e[0m" << " take " << amount << " damage" << std::endl;
		this->_hitPoints -= amount;
	}
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::string color;

	color = getColor(this->_name);

	if (this->_energyPoints <= 0)
	{
		std::cout << color << "\e[1m" << "\e[3m" << this->_name <<  "\e[0m" << " can't repaired himself, low energy" << std::endl;		
		return ;
	}
	std::cout << color << "\e[1m" << "\e[3m" << this->_name <<  "\e[0m" << " repaired himself of " << amount << " hitpoints" << std::endl;
	this->_hitPoints += amount;
	this->_energyPoints--;
	return ;
}

std::string	ClapTrap::getColor(std::string name)
{
	std::string	color;
	
	if (name == "Jackie")
		color = "\e[38;2;255;156;241m";
	else if (name == "Bibi")
		color = "\e[38;2;255;125;125m";
	else if (name == "Remu")
		color = "\e[38;2;186;255;238m";
	else
		color = "\e[38;2;246;255;101m";
	return (color);
}

void	ClapTrap::visualizePoints()
{
	std::string	color;

	color = getColor(this->_name);

	std::cout  << color << "┌─────────────────────────────────────────────────────┐" <<  "\e[0m" << std::endl;
	std::cout << color << "│" << "\e[3m" <<  "\e[0m" << "\e[1m" ;
	std::cout << std::setw(22) << this->_name ;
	std::cout << " total point : "  <<  "\e[0m"   << color << std::setw(19)  << "│" <<  "\e[0m" << std::endl;
	
	std::cout << color << "│" <<  "\e[0m" << std::setw(3) << this->_hitPoints << " hit points  " << std::setw(3) << this->_energyPoints << " energy points  " << std::setw(3) << this->_attackDamage << " attack damage " << color  << "│" <<  "\e[0m" << std::endl;

	std::cout << color << "└─────────────────────────────────────────────────────┘" <<  "\e[0m" << std::endl;
}