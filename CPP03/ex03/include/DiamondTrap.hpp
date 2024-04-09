#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap 
{
	public :
		
		DiamondTrap(void);
		DiamondTrap(DiamondTrap const & src);
		DiamondTrap(std::string name);
		
		~DiamondTrap(void);

		DiamondTrap &	operator=(DiamondTrap const & src);

		void	whoAmI();

	private :
		std::string	_name;
};

#endif