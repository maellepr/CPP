#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{ 
	public :
		Ice(void);
		// Character(std::string const & type);
		Ice(Ice const & src);
		~Ice(void);

		Ice &	operator=(Ice const & src);
		
		Ice*	clone(void) const;
		void	use(ICharacter& target);
	protected :

};

#endif