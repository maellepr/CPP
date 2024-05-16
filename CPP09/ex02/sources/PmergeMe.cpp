#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe(void) : _oddNb(-1), _index(0)
{
	return ;
}

PmergeMe::PmergeMe(PmergeMe const & src)
{
	if (this != &src)
		*this = src;
}

PmergeMe::~PmergeMe(void)
{
	return ;
}

PmergeMe & PmergeMe::operator=(PmergeMe const & src)
{
	if (this != &src)
		*this = src;
	return (*this);
}

void	PmergeMe::MergeInsertion(int ac, char **av)
{
	_toVector(ac, av);
	std::cout << "Before:";
	_printVector(this->_vec);
	_sortVector();
	// _sortDeque();
}

void	PmergeMe::_toVector(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		std::istringstream iss(av[i]);
		unsigned int		nb;
		char				rest; 
		if (iss >> nb && !(iss >> rest)) 
			this->_vec.push_back(nb);
		else
		{
			throw Error();
		}
	}
}

void	PmergeMe::_printVector(std::vector<unsigned int> vec)
{
	// for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	// 	std::cout << ' ' << *it;

	for (unsigned int i = 0; i < vec.size(); i++)
		std::cout << ' ' << vec[i];
	std::cout << std::endl;
}

void	PmergeMe::_sortVector()
{
	//ajouter le temps chronometre
	
	//Faire les pairs
	// std::cout << "size = " << _vec.size() << std::endl;
	if (_vec.size() % 2 != 0)
	{
		// _inf.push_back(_vec[_vec.size()]);
		_oddNb = _vec[_vec.size() - 1];
		std::cout << "oddNb = " << _oddNb << std::endl;
		_vec.pop_back();
	}
	// std::cout << "vec pop back :";
	// for (unsigned int i = 0; i < _vec.size(); i++)
	// 	std::cout << ' ' << _vec[i]; std::cout << std::endl;

	for (unsigned int i = 0; i < _vec.size(); i+=2)
	{
		if (_vec[i] <= _vec[i + 1])
		{
			_inf.push_back(_vec[i]);
			_sup.push_back(_vec[i + 1]);
		}
		else
		{
			_inf.push_back(_vec[i + 1]);
			_sup.push_back(_vec[i]);
		}
	}

	std::cout << "inf : ";
	for (unsigned int i = 0; i < _inf.size(); i++)
		std::cout << '	' << _inf[i];
	std::cout << std::endl;

	std::cout << "sup : ";
	for (unsigned int i = 0; i < _sup.size(); i++)
		std::cout << '	' << _sup[i];
	std::cout << std::endl;

	//Trier les pairs par ordre croissant avec leur superieurs
	// for (unsigned int i = 0; i < (_sup.size() - 1); i++)
	unsigned int i = 0;
	while (i < (_sup.size() - 1))
	{
		int tmp;
		if (_sup[i] > _sup[i + 1])
		{
			tmp = _sup[i + 1];
			_sup[i + 1] = _sup[i];
			_sup[i] = tmp;
			tmp = _inf[i + 1];
			_inf[i + 1] = _inf[i];
			_inf[i] = tmp;
			i = 0;
		}
		else
			i++;
	}
	if (_oddNb >= 0)
		_inf.push_back(_oddNb);
	std::cout << "inf : ";
	for (unsigned int i = 0; i < _inf.size(); i++)
		std::cout << '	' << _inf[i];
	std::cout << std::endl;

	std::cout << "sup : ";
	for (unsigned int i = 0; i < _sup.size(); i++)
		std::cout << '	' << _sup[i];
	std::cout << std::endl;

	//Remettre tous les superieurs tries dans _vec final
	for (unsigned int i = 0; i < _sup.size(); i++)
		_vecFinal.push_back(_sup[i]);
	
	// std::cout << "vecF : ";
	// for (unsigned int i = 0; i < _vecFinal.size(); i++)
	// 	std::cout << '	' << _vecFinal[i];
	// std::cout << std::endl;	
	
	// Trier les inferieurs
	// On commence par placer indice 1
	_vecFinal.insert(_vecFinal.begin(), _inf[1 - 1]);


	unsigned int preJacob = 1;
	unsigned int ppreJacob = 1;
	unsigned int tmp;
	

	tmp = preJacob;
	preJacob = tmp + 2 * ppreJacob - 1;
	ppreJacob = tmp - 1;

	std::cout << "_vecFinal : ";
	for (unsigned int i = 0; i < _vecFinal.size(); i++)
		std::cout << '	' << _vecFinal[i];	
	std::cout << "\nsize = " << _vecFinal.size() << std::endl;

	std::cout << "pre = " << preJacob << " ppre = " << ppreJacob << std::endl;

	unsigned int low = 0;
	unsigned int high = _vecFinal.size() - 1; 
	unsigned int mid = low + (high - low) / 2;

	unsigned int _index = preJacob;


	while (_index < _inf.size())//on remet a jour la valeur de Jacob
	{
		
		while (_index > ppreJacob)//on trie les _index entre preJacob et ppreJacob _index[3] _index[2]
		{	

			// mid = _doDichotomy(low, high, mid);
			while ((high - low) > 1)//on trie un _index par un
			{
				if (_vecFinal[mid] < _inf[_index])//go moitie droite
				{
					low = mid;
					// high = high;
					mid = low + (high - low) / 2;
				}
				else if (_vecFinal[mid] > _inf[_index])//go moitie gauche
				{
					// low = low;
					high = mid;
					mid = low + (high - low) / 2;
				}
				// std::cout << "mid = " << mid  << " low = " << low  << " high = " << high << std::endl;
			}
			std::cout << "insert:" << _inf[_index] << "\n";
			if (mid == 0 && (_inf[_index] < _vecFinal[mid]))
				_vecFinal.insert(_vecFinal.begin(), _inf[_index]);
			else
				_vecFinal.insert(_vecFinal.begin() + mid + 1, _inf[_index]);
			
			_index--;
			low = 0;
			high = _vecFinal.size() - 1;
			mid = low + (high - low) / 2;
		}
		preJacob++;
		ppreJacob++;
		tmp = preJacob;
		preJacob = tmp + 2 * ppreJacob - 1;
		ppreJacob = tmp - 1;		
		_index = preJacob;
		if (_index >= _inf.size() && _vecFinal.size() != _vec.size())//a changer par vrai valeur (nb de chiffre entres)
		{
			_index = ppreJacob + 1;
			while (_index < _inf.size())
			{
					// mid = _doDichotomy(low, high, mid);
					while ((high - low) > 1)//on trie un _index par un (_index [3], _index [2])
					{
						if (_vecFinal[mid] < _inf[_index])//go moitie droite
						{
							low = mid;
							// high = high;
							mid = low + (high - low) / 2;
						}
						else if (_vecFinal[mid] > _inf[_index])//go moitie gauche
						{
							// low = low;
							high = mid;
							mid = low + (high - low) / 2;
						}
						// std::cout << "mid = " << mid << std::endl;
					}
					std::cout << "insert\n";
					if (mid == 0 && (_inf[_index] < _vecFinal[mid]))
						_vecFinal.insert(_vecFinal.begin(), _inf[_index]);
					else
						_vecFinal.insert(_vecFinal.begin() + mid + 1, _inf[_index]);
					// _index--;
					low = 0;
					high = _vecFinal.size() - 1;
					mid = low + (high - low) / 2;				
				
				_index++;
			}
		}
		std::cout << "pre = " << preJacob << " ppre = " << ppreJacob << " _index = " << _index << std::endl;
	}
	
	std::cout << "_vecFinal :: ";
	for (unsigned int i = 0; i < _vecFinal.size(); i++)
		std::cout << '	' << _vecFinal[i];	
	std::cout << "\nsize = " << _vecFinal.size() << std::endl;
	isSortedVec(_vecFinal);
}

unsigned int	PmergeMe::_doDichotomy(unsigned int low, unsigned int high, unsigned int mid)
{
	while ((high - low) > 1)//on trie un _index par un
	{
		if (_vecFinal[mid] < _inf[_index])//go moitie droite
		{
			low = mid;
			// high = high;
			mid = low + (high - low) / 2;
		}
		else if (_vecFinal[mid] > _inf[_index])//go moitie gauche
		{
			// low = low;
			high = mid;
			mid = low + (high - low) / 2;
		}
		std::cout << "mid = " << mid  << " low = " << low  << " high = " << high << std::endl;
	}
	return (mid);
}

void	PmergeMe::isSortedVec(std::vector<unsigned int> vec)
{
	for (unsigned int i = 0; i < (vec.size() - 1); i++)
	{
		if (vec[i] > vec[i + 1])
		{
			std::cout << "Not sorted :////\n";
			return ;
		}
	}
	std::cout << "Sorted !\n";
}