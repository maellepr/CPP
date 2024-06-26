#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	public :
		Dog(void);
		Dog(Dog const & src);
		virtual ~Dog(void);

		Dog	&	operator=(Dog const & src);

		virtual void	makeSound(void) const;

		Brain *			getBrain() const;
	private :
		Brain	*_brain;
};

#endif