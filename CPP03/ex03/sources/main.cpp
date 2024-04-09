#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"
#include "../include/DiamondTrap.hpp"

int main(void)
{
	std::string	claptrap1Name = "Jackie";
	std::string	scavtrap1Name = "Momo";
	std::string	fragtrap1Name = "Remu";
	std::string	diamondtrapName = "Ruby";

	ClapTrap	claptrap1(claptrap1Name);
	ScavTrap	scavtrap1(scavtrap1Name);
	FragTrap	fragtrap1(fragtrap1Name);
	DiamondTrap	diamondtrap1(diamondtrapName);

	claptrap1.visualizePoints();
	scavtrap1.visualizePoints();
	fragtrap1.visualizePoints();
	diamondtrap1.visualizePoints();

	diamondtrap1.whoAmI();

	diamondtrap1.attack(claptrap1Name);
	claptrap1.takeDamage(diamondtrap1.getAttackDamage());

	diamondtrap1.attack(scavtrap1Name);
	scavtrap1.takeDamage(diamondtrap1.getAttackDamage());

	claptrap1.beRepaired(5);
	diamondtrap1.beRepaired(5);

	// claptrap2.attack(scavtrap1.getName());
	// scavtrap1.takeDamage(2);

	scavtrap1.guardGate();
	diamondtrap1.highFivesGuys();

	claptrap1.visualizePoints();
	scavtrap1.visualizePoints();
	fragtrap1.visualizePoints();
	diamondtrap1.visualizePoints();

	// std::string diamondTrapName = "DT-XXY";
	// std::string scavTrapName = "SCVT-2000";
	// std::string clapTrapName = "CT-42";

	// DiamondTrap	diamondTrap(diamondTrapName);
	// ScavTrap	scavTrap(scavTrapName);
	// ClapTrap	clapTrap(clapTrapName);

	// diamondTrap.whoAmI();
	// clapTrap.attack(scavTrapName);
	// scavTrap.takeDamage(clapTrap.getAttackDamage());
	// scavTrap.attack(clapTrapName);
	// clapTrap.takeDamage(scavTrap.getAttackDamage());
	// diamondTrap.attack(scavTrapName);
	// scavTrap.takeDamage(diamondTrap.getAttackDamage());
	// diamondTrap.highFivesGuys();
	// diamondTrap.guardGate();
	// diamondTrap.takeDamage(5000);
	// diamondTrap.beRepaired(5000);
	// diamondTrap.whoAmI();
	// return (0);
}