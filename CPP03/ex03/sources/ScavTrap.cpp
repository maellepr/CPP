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
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	// this->_name = name; // decommenter si ScavTrap::_name existe
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;	
	std::cout << "ScavTrap constructor called with name initialized " << "\e[1m" << "\e[3m" << name << "\e[0m" <<  std::endl;
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
	std::cout << "ScavTrap Destructor called, " << "\e[1m" << "\e[3m" << this->_name <<  "\e[0m" << " was destroyed " << std::endl;
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

void	ScavTrap::attack(std::string& target)
{
	std::string color;
	std::string color2;

	color = getColor(this->_name);
	color2 = getColor(target);

	if (this->_energyPoints == 0)
	{
		std::cout << "ScavTrap : No more energy points ! " << color << "\e[1m" << "\e[3m" << this->_name << "\e[0m"  << " can't attack !"<< std::endl;
		return ;
	}
	if (this->_hitPoints == 0)
	{
		std::cout << "ScavTrap : No more hit points ! " << color << "\e[1m" << "\e[3m" << this->_name << "\e[0m" << " can't attack ! " << std::endl;
		return ;
	}
	if (this->_name == target)
		std::cout << "ScavTrap : " << color2 << "\e[1m" << "\e[3m" << target << "\e[0m" << " is attacking himself !" << std::endl;
	else
		std::cout << "ScavTrap : " << color << "\e[1m" << "\e[3m" << this->_name << "\e[0m" << " attack " << target << " !" << std::endl; 
	this->_energyPoints--;
	return ;
}

void	ScavTrap::guardGate(void)
{
	std::string	color = getColor(this->_name);
	
	std::cout << color << "\e[1m" << "\e[3m" << this->_name <<  "\e[0m" << " is now in gate keeper mode !"<< std::endl;

}
