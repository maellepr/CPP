#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <iomanip>

class ClapTrap {
	public :
		
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & src);
		~ClapTrap(void);

		ClapTrap &	operator=(ClapTrap const & src);

		std::string			getName(void) const;
		unsigned int		getHitPoints(void) const;
		unsigned int		getEnergyPoints(void) const;
		unsigned int		getAttackDamage(void) const;

		// void		setName(std::string name) const;
		// void		setHitPoints(unsigned int hitPoint) const;
		// void		setEnergyPoints(unsigned int energyPoints) const ;
		// void		setAttackDamage(unsigned int attackDamage) const ;

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		void				visualizePoints();
	private :
		std::string			_getColor(std::string name);

	protected:
		ClapTrap(void);

		std::string			_name;
		unsigned int		_hitPoints;
		unsigned int		_energyPoints;
		unsigned int		_attackDamage;		

};

#endif