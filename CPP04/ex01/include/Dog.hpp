#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public :
		Dog(void);
		Dog(std::string type);
		Dog(Dog const & src);
		virtual ~Dog(void);

		Dog	&	operator=(Dog const & src);

		virtual void	makeSound(void) const;
	private :
		Brain	*_brain;
};

#endif