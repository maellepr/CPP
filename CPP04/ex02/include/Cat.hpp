#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	public :
		Cat(void);
		Cat(Cat const & src);
		virtual ~Cat(void);

		Cat	&	operator=(Cat const & src);

		virtual void	makeSound(void) const;
	
		Brain *			getBrain() const;
	private :
		Brain	*_brain;
};

#endif