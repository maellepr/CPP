#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"

int main(void)
{
	ClapTrap	claptrap1("Jackie");
	ClapTrap	claptrap2("Bibi");
	ScavTrap	scavtrap1("Momo");
	FragTrap	fragtrap1("Remu");


	claptrap1.visualizePoints();
	claptrap2.visualizePoints();
	scavtrap1.visualizePoints();
	fragtrap1.visualizePoints();

	claptrap1.attack(fragtrap1.getName());
	fragtrap1.takeDamage(50);

	claptrap1.visualizePoints();
	claptrap2.visualizePoints();
	scavtrap1.visualizePoints();
	fragtrap1.visualizePoints();

	claptrap2.beRepaired(3);

	claptrap2.attack(scavtrap1.getName());
	scavtrap1.takeDamage(2);

	fragtrap1.highFivesGuys();

	for (int i = 0; i < 25; i++)
	{
		fragtrap1.attack(scavtrap1.getName());
		scavtrap1.takeDamage(fragtrap1.getAttackDamage());
	}

	fragtrap1.attack(claptrap1.getName());
	claptrap1.takeDamage(fragtrap1.getAttackDamage());

	claptrap1.attack(fragtrap1.getName());
	fragtrap1.takeDamage(150);

	fragtrap1.highFivesGuys();

	scavtrap1.attack(claptrap2.getName());
	claptrap2.takeDamage(scavtrap1.getAttackDamage());

	scavtrap1.guardGate();

	claptrap1.visualizePoints();
	claptrap2.visualizePoints();
	scavtrap1.visualizePoints();
	fragtrap1.visualizePoints();

}