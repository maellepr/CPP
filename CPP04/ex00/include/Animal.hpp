#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <iomanip>

// #define	BOLD  
// #define	YELLOW
// #define	PINK
// #define	BLUE
// #define RESET

class Animal {
	public :
		Animal(void);
		Animal(std::string const type);
		Animal(Animal const & src);
		virtual ~Animal(void);

		Animal &	operator=(Animal const & src);
		
		std::string const	& getType(void) const;

		virtual void	makeSound(void) const;

	protected :
		std::string	_type;

};

#endif