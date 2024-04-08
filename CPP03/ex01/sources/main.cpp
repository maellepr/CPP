#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"

int main(void)
{
	ClapTrap	claptrap1("Jackie");
	ClapTrap	claptrap2("Bibi");

	claptrap1.attack(claptrap2.getName());
	claptrap2.takeDamage(10);
	
	claptrap1.visualizePoints();
	claptrap2.visualizePoints();

	claptrap2.attack(claptrap1.getName());
	claptrap2.beRepaired(3);
	claptrap2.attack(claptrap1.getName());
	claptrap1.takeDamage(2);
	claptrap2.attack(claptrap2.getName());
	claptrap2.takeDamage(1);

	claptrap1.visualizePoints();
	claptrap2.visualizePoints();

	for (int i = 0; i < 6; i++)
	{
		claptrap2.attack(claptrap1.getName());
		claptrap1.takeDamage(2);
	}

}