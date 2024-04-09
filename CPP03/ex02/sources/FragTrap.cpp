#include "../include/FragTrap.hpp"

/**** Default constructor ****/
FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	return ;
}

/**** Constructor taking the name as parameter ****/
FragTrap::FragTrap(std::string const name) : ClapTrap()
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;	
	std::cout << "FragTrap constructor called with name initialized" << std::endl;
	return ;
}

/**** Copy constructor ****/
FragTrap::FragTrap(FragTrap const & src) : ClapTrap()
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	// *this = src;// a changer peut etre
	this->_name = src.getName();
	this->_hitPoints = src.getHitPoints();
	this->_energyPoints = src.getEnergyPoints();
	this->_attackDamage = src.getAttackDamage();
	return ;
}

/**** Destructor ****/
FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap Destructor called" << std::endl;
	return ;
}

/**** Operator ****/
FragTrap &	FragTrap::operator=(FragTrap const & src)
{
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	if (this != &src) {
		this->_name = src.getName();
		this->_hitPoints = src.getHitPoints();
		this->_energyPoints = src.getEnergyPoints();
		this->_attackDamage = src.getAttackDamage();
	}
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::string color;

	color = getColor(this->_name);

	if (this->_hitPoints <= 0 || this->_energyPoints <= 0)
	{
		std::cout << color << "\e[1m" << "\e[3m" << this->_name <<  "\e[0m" << " can't do high fives, low energy" << std::endl;		
		return ;
	}
	std::cout << color << "\e[1m" << "\e[3m" << this->_name <<  "\e[0m" << " : high fives anyone !?" << std::endl;		
}