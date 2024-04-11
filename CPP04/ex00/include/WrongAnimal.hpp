#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <iomanip>

class WrongAnimal {
	public :
		WrongAnimal(void);
		WrongAnimal(std::string const type);
		WrongAnimal(WrongAnimal const & src);
		virtual ~WrongAnimal(void);

		WrongAnimal &	operator=(WrongAnimal const & src);
		
		std::string const	& getType(void) const;

		void	makeSound(void) const;

	protected :
		std::string	_type;

};

#endif