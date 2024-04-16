#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public :
		MateriaSource(void);
		MateriaSource(MateriaSource const & materiasource);
		virtual ~MateriaSource(void);

		MateriaSource & operator=(MateriaSource const & materiasource);

		void		learnMateria(AMateria* m);
		AMateria*	createMateria(std::string const & type);
	protected :
		static int const	_inventorySize = 4;
		AMateria *			_savingInventory[_inventorySize];
		void				_setEmptyInventory(void);
		void				_deleteInventory(void);
};

#endif