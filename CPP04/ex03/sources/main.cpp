#include "../include/MateriaSource.hpp"
#include "../include/Character.hpp"
#include "../include/Ice.hpp"
#include "../include/Cure.hpp"

int main()
{
	// std::cout << std::endl << BOLD << "*** Tests from the subject ***" << RESET << std::endl << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}

	// {
	// 	//------------------------------------------------------------------------------------------------------//
	// 	std::cout << std::endl << BOLD << "*** Testing Materia ***" << RESET << std::endl << std::endl;
	// 	IMateriaSource * src = new MateriaSource();
	// 	AMateria * icy1 = new Ice();
	// 	AMateria * icy2 = new Ice();
	// 	AMateria * icy3 = new Ice();
	// 	AMateria * cure1 = new Cure();
	// 	AMateria * cure2 = new Cure();
	// 	std::cout << BOLD << " -- Learning Materia --" << RESET << std::endl;
	// 	src->learnMateria(icy1);
	// 	src->learnMateria(icy2);
	// 	src->learnMateria(icy3);
	// 	src->learnMateria(cure1);
	// 	std::cout << BOLD << " -- 4 Materia has been learn, the saving inventory should be full -- " << RESET << std::endl; 
	// 	src->learnMateria(cure2);
	// 	std::cout << BOLD << " -- Creating material (ice and cure) --" << RESET << std::endl;
	// 	AMateria * newIce = src->createMateria("ice");
	// 	AMateria * newCure = src->createMateria("cure");
	// 	std::cout << BOLD << " -- Creating a non existing type (unknown type) --" << RESET << std::endl;
	// 	src->createMateria("unkown type");

	// 	//------------------------------------------------------------------------------------------------------//
	// 	std::cout << std::endl << BOLD << "*** Testing Character ***" << RESET << std::endl << std::endl;		
	// 	std::cout << BOLD << " -- Characters creation --" << RESET << std::endl;
	// 	Character * Mimi = new Character("Mimi");
	// 	Character * Jackie = new Character("Jackie");
	// 	std::cout << BOLD << " -- Creating 4 Materia for the Character to equip --" << RESET << std::endl;
	// 	AMateria * tmp1 = src->createMateria("ice");
	// 	Mimi->equip(tmp1);
	// 	AMateria * tmp2 = src->createMateria("cure");
	// 	Mimi->equip(tmp2);
	// 	AMateria * tmp3 = src->createMateria("ice");
	// 	Mimi->equip(tmp3);
	// 	AMateria * tmp4 = src->createMateria("cure");
	// 	Mimi->equip(tmp4);
	// 	std::cout << BOLD << " -- Creating a 5th Materia for the Character to equip -> Full inventory --" << RESET << std::endl;
	// 	AMateria * tmp5 = src->createMateria("ice");
	// 	Mimi->equip(tmp5);
	// 	std::cout << BOLD << " -- Display Inventory -- " << RESET << std::endl;
	// 	Mimi->displayInventory();
	// 	std::cout << BOLD << " -- Fully unequip the Character --" << RESET << std::endl;
	// 	for (int i = 0; i < 4; i++)
	// 		Mimi->unequip(i);
	// 	std::cout << BOLD << " -- Unequip the Character with a index already empty --" << RESET << std::endl;
	// 	Mimi->unequip(0);
	// 	std::cout << BOLD << " -- Unequip the Character with a wrong index --" << RESET << std::endl;
	// 	Mimi->unequip(6);
	// 	std::cout << "---------------------------------" << std::endl;
	// 	Mimi->unequip(-1);
	// 	std::cout << BOLD << " -- Display Inventory -- " << RESET << std::endl;
	// 	Mimi->displayInventory();
	// 	std::cout << BOLD << " -- Equip of 2 Materia in the Character inventory -- " << RESET << std::endl;
	// 	Mimi->equip(tmp1);
	// 	Mimi->equip(tmp2);

	// 	std::cout << BOLD << " -- Check use function -- " << RESET << std::endl;
	// 	Mimi->use(0, *Jackie);
	// 	std::cout << BOLD << " -- Check use on empty inventory -- " << RESET << std::endl;
	// 	Mimi->use(2, *Jackie);
	// 	std::cout << BOLD << " -- Check use with wrong index -- " << RESET << std::endl;
	// 	Mimi->use(7, *Jackie);

	// 	//------------------------------------------------------------------------------------------------------//
	// 	std::cout << std::endl << BOLD << "*** Creating a Character by copy of another Character ***" << RESET << std::endl << std::endl;
	// 	Character *Copy = new Character(*Mimi);
	// 	std::cout << BOLD << " -- Display Inventory -- " << RESET << std::endl;
	// 	Copy->displayInventory();
	// 	std::cout << BOLD << " -- Check use function -- " << RESET << std::endl;
	// 	Copy->use(0, *Jackie);
	// 	Copy->use(1, *Jackie);
	// 	std::cout << BOLD << " -- Check use on empty inventory -- " << RESET << std::endl;
	// 	Copy->use(2, *Jackie);
	// 	std::cout << BOLD << " -- Check use with wrong index -- " << RESET << std::endl;
	// 	Copy->use(7, *Jackie);	

	// 	//------------------------------------------------------------------------------------------------------//
	// 	std::cout << std::endl << BOLD << "*** Creating a Character by copy assignement ***" << RESET << std::endl << std::endl;
	// 	Character *CopyAssign = new Character();
	// 	*CopyAssign = *Mimi;
	// 	std::cout << BOLD << " -- Display Inventory -- " << RESET << std::endl;
	// 	CopyAssign->displayInventory();
	// 	std::cout << BOLD << " -- Check use function -- " << RESET << std::endl;
	// 	CopyAssign->use(0, *Jackie);
	// 	CopyAssign->use(1, *Jackie);
	// 	std::cout << BOLD << " -- Check use on empty inventory -- " << RESET << std::endl;
	// 	CopyAssign->use(2, *Jackie);
	// 	std::cout << BOLD << " -- Check use with wrong index -- " << RESET << std::endl;
	// 	CopyAssign->use(7, *Jackie);	

	// 	//------------------------------------------------------------------------------------------------------//
	// 	std::cout << std::endl << BOLD << "*** Deleting all instances ***" << RESET << std::endl << std::endl;
	// 	// delete tmp1;
	// 	// delete tmp2;
	// 	delete tmp3;
	// 	delete tmp4;
	// 	delete tmp5;
	// 	delete cure2;
	// 	delete src;
	// 	delete newIce;
	// 	delete newCure;
	// 	delete Mimi;
	// 	delete Jackie;
	// 	delete Copy;
	// 	delete CopyAssign;
	// }

	// std::cout << std::endl << std::endl << BOLD << "*** Testing deep copy ***" << RESET << std::endl;
	// Character basic;

	// IMateriaSource * src = new MateriaSource();

	// AMateria * icy1 = new Ice();

	// src->learnMateria(icy1);

	// AMateria * tmppp = src->createMateria("ice");
	// basic.equip(tmppp);
	// basic.displayInventory();
	// {
	// 	Character tmp = basic;
	// 	tmp.displayInventory();	
	// }
	// basic.displayInventory();
	// delete src;
}