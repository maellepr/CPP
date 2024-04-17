#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

int main(void)
{
	{
		std::cout << BOLD << std::endl << "*** Tests from the subject ***" << RESET << std::endl << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		std::cout << std::endl;
		delete i;
		delete j;
		delete meta;
	}

	// {
	// 	std::cout << BOLD << std::endl << "*** Copying a dog with copy constructor ***" << RESET << std::endl << std::endl;
	// 	Animal *	dog = new Dog();
	// 	Animal *	copyDog = new Animal(*dog);
		
	// 	dog->makeSound();
	// 	copyDog->makeSound();

	// 	delete copyDog;
	// 	delete dog;
		
	// }
	// {
	// 	std::cout << BOLD << std::endl << "*** Copying a cat with copy assignement ***" << RESET << std::endl << std::endl;
	// 	Animal *	cat = new Cat();
	// 	Animal *	copyCat = new Animal();

	// 	*copyCat = *cat;
		
	// 	cat->makeSound();
	// 	copyCat->makeSound();

	// 	delete copyCat;
	// 	delete cat;
		
	// }

	// {
	// 	std::cout << BOLD << std::endl << "*** Copying a cat with copy assignement to a dog ***" << RESET << std::endl << std::endl;
	// 	Animal *	cat = new Cat();
	// 	Animal *	dog = new Dog();

	// 	*dog = *cat;
		
	// 	cat->makeSound();
	// 	dog->makeSound();

	// 	delete dog;
	// 	delete cat;
		
	// }

	{
		std::cout << BOLD << std::endl << "*** Tests with wrongAnimal ***" << RESET << std::endl;
		std::cout << std::endl;
		
		const WrongAnimal* meta2 = new WrongAnimal();
		const WrongAnimal* i2 = new WrongCat();
		const WrongCat* j2 = new WrongCat();

		std::cout << i2->getType() << " " << std::endl;

		// Ils vont tout deux afficher le son du wrong animal et non du wrong cat
		meta2->makeSound();
		i2->makeSound();
		// Celui affichera le son du wrong cat
		j2->makeSound();

		delete i2;
		delete j2;
		delete meta2;
	}

	return 0;
}