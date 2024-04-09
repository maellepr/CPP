#include "../include/DiamondTrap.hpp"

/**** Default constructor ****/
DiamondTrap::DiamondTrap(void) : FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	return ;
}

/**** Constructor taking the name as parameter ****/
DiamondTrap::DiamondTrap(std::string name) 
: ClapTrap(name + "_clap_name"), FragTrap(name + "_frag_name"), ScavTrap(name + "_scav_name"), _name(name)
{
	// this->_name = name;
	std::cout << "DiamondTrap constructor called with name " << " initialized " << "\e[1m" << "\e[3m" << name << "\e[0m" << std::endl;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	return ;
}

/**** Copy constructor ****/
DiamondTrap::DiamondTrap(DiamondTrap const & src) : ClapTrap(),  FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	// *this = src;// a changer peut etre
	this->_name = src.getName();
	this->_hitPoints = src.getHitPoints();
	this->_energyPoints = src.getEnergyPoints();
	this->_attackDamage = src.getAttackDamage();
	return ;
}

/**** Destructor ****/
DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called, "  << "\e[1m" << "\e[3m" << this->_name <<  "\e[0m" << " was destroyed" << std::endl;
	return ;
}

/**** Operator ****/
DiamondTrap &	DiamondTrap::operator=(DiamondTrap const & src)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &src) {
		this->_name = src.getName();
		this->_hitPoints = src.getHitPoints();
		this->_energyPoints = src.getEnergyPoints();
		this->_attackDamage = src.getAttackDamage();
	}
	return (*this);
}

void	DiamondTrap::whoAmI()
{
	std::string color;
	std::string	color2;

	color = getColor(this->_name);
	color2 = getColor(ClapTrap::_name);

	std::cout << "My name is " << color << "\e[1m" << "\e[3m" << this->_name <<  "\e[0m" << " and my ClapTrap name is " << color2 << "\e[1m" << "\e[3m" << ClapTrap::_name <<  "\e[0m" <<  std::endl;
}