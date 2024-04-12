#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{ 
	public :
		Cure(void);
		// Character(std::string const & type);
		Cure(Cure const & src);
		~Cure(void);

		Cure &	operator=(Cure const & src);

		Cure*	clone(void) const;
		void	use(ICharacter& target);
	protected :

};

#endif