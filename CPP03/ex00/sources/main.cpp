#include "../include/ClapTrap.hpp"

int main(void)
{
	ClapTrap	claptrap1("Jackie");
	ClapTrap	claptrap2("Bibi");

	claptrap1.beRepaired(0);
	claptrap1.attack(claptrap2.getName());
	claptrap2.takeDamage(10);
	claptrap2.attack(claptrap1.getName());
	claptrap2.beRepaired(3);
	claptrap2.attack(claptrap1.getName());
	claptrap1.takeDamage(2);
	claptrap2.attack(claptrap2.getName());
}