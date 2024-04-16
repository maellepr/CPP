#ifndef CHARACTER_HPP
#define CHARACTER_HPP

// #include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
	public :
		Character(void);
		Character (std::string const name);
		Character(Character const & character);
		~Character(void);//virtual ou non?

		Character &	operator=(Character const & src);
		
		std::string const &	getName(void) const;
		void				setname(std::string const name);
		
		void				equip(AMateria* m);
		void				unequip(int idx);
		void 				use(int idx, ICharacter& target);
		void				displayInventory(void) const;
	protected ://prive ou protected ?
		std::string			_name;//
		static int const	_inventorySize = 4;
		AMateria *			_inventory[_inventorySize];
		void				_setEmptyInventory(void);
		void				_deleteInventory(void);
};

#endif