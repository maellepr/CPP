#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

#define NB_ANIMALS 4

int main(void)
{
	{
		std::cout << BOLD << "Creating one dog and one cat" << RESET << std::endl;
		// AAnimal test;
		const Dog* j = new Dog();
		const Cat* i = new Cat();
		delete j;//should not create a leak
		delete i;
	}
	// std::cout << std::endl;
	// {
	// 	std::cout << BOLD << "Creating an array of " << NB_ANIMALS << " Animals, filled half with cats, half with dogs" << RESET << std::endl;
	// 	AAnimal	*animalArray[NB_ANIMALS];
	// 	for (int i = 0; i < NB_ANIMALS / 2; i++)
	// 		animalArray[i] = new Cat();
	// 	for (int i = NB_ANIMALS / 2; i < NB_ANIMALS; i++)
	// 		animalArray[i] = new Dog();
	// 	for (int i = 0; i < NB_ANIMALS / 2; i++)
	// 		animalArray[i]->makeSound();
	// 	for (int i = NB_ANIMALS / 2; i < NB_ANIMALS; i++)
	// 		animalArray[i]->makeSound();
	// 	for (int i = 0; i < NB_ANIMALS / 2; i++)
	// 		delete animalArray[i];
	// 	for (int i = NB_ANIMALS / 2; i < NB_ANIMALS; i++)
	// 		delete animalArray[i];
		
	// }
	std::cout << std::endl;
	{
		std::cout << BOLD << "Creating two cats and putting ideas in each of them to verify they both have their own deep copy" << RESET << std::endl;
		std::cout << std::endl;

		std::cout << "First cat creation" << std::endl;
		Cat	*cat = new Cat();
		cat->getBrain()->setIdeas(0, "the cat : Miaou I should take a nap...");
		cat->getBrain()->setIdeas(1, "the cat : Time for a little walk outside miaou !");
		cat->getBrain()->setIdeas(2, "the cat : Rrron rrron I'm a cat rron rron");
		std::cout << std::endl;

		std::cout << "First cat ideas :" << std::endl;
		std::cout << cat->getBrain()->getIdea(0) << std::endl;
		std::cout << cat->getBrain()->getIdea(1) << std::endl;
		std::cout << cat->getBrain()->getIdea(2) << std::endl;

		std::cout << std::endl;
		std::cout << "Second cat creation by copy" << std::endl;
		Cat	*catCopy = new Cat(*cat);
		
		std::cout << std::endl;
		std::cout << "Second cat ideas :" << std::endl;		
		std::cout << catCopy->getBrain()->getIdea(0) << std::endl;
		std::cout << catCopy->getBrain()->getIdea(1) << std::endl;
		std::cout << catCopy->getBrain()->getIdea(2) << std::endl;
		std::cout << std::endl;

		std::cout << "Putting new ideas into second cat" << std::endl;
		catCopy->getBrain()->setIdeas(0, "the cat copy : Miaou I'm hungry");
		catCopy->getBrain()->setIdeas(1, "the cat copy : Miaou miaou miaou miaaaouu");
		catCopy->getBrain()->setIdeas(2, "the cat copy : I need some fancy food...");
		std::cout << std::endl;

		std::cout << "Second cat ideas :" << std::endl;
		std::cout << catCopy->getBrain()->getIdea(0) << std::endl;
		std::cout << catCopy->getBrain()->getIdea(1) << std::endl;
		std::cout << catCopy->getBrain()->getIdea(2) << std::endl; 
		std::cout << std::endl;

		std::cout << "Deleting first cat" << std::endl;
		delete cat;
		std::cout << "Deleting second cat" << std::endl;
		delete catCopy;

	}
	return 0;
}