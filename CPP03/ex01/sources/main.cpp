#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"

int main(void)
{
	ClapTrap	claptrap1("Jackie");
	ClapTrap	claptrap2("Bibi");
	ScavTrap	scavtrap1("Momo");

	claptrap1.visualizePoints();
	claptrap2.visualizePoints();
	scavtrap1.visualizePoints();

	claptrap1.attack(claptrap2.getName());
	claptrap2.takeDamage(10);

	claptrap1.visualizePoints();
	claptrap2.visualizePoints();
	scavtrap1.visualizePoints();

	claptrap2.attack(claptrap1.getName());
	claptrap2.beRepaired(3);

	claptrap2.attack(scavtrap1.getName());
	scavtrap1.takeDamage(2);
	
	scavtrap1.attack(claptrap2.getName());
	claptrap2.takeDamage(scavtrap1.getAttackDamage());

	scavtrap1.guardGate();

	claptrap1.attack(scavtrap1.getName());
	scavtrap1.takeDamage(100);

	claptrap1.visualizePoints();
	claptrap2.visualizePoints();
	scavtrap1.visualizePoints();

}