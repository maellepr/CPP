#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe(void) : _oddNb(-1), _index(0), _oddNbd(-1), _indexd(0)
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
	size = ac - 1;
	clock_t	tVec;
	_toVector(ac, av);
	_sortVector();
	tVec = clock();

	clock_t tDeq;
	_toDeque(ac, av);
	_sortDeque();
	tDeq = clock();

	std::cout << "Before: ";
	for (int i = 1; i < ac; i++)
		std::cout << av[i] << ' ';
	std::cout << std::endl << "After: ";
	_printVector(this->_vecFinal);
	isSortedVec(_vecFinal);
	isSortedDeq(_deqFinal);
	isSameSize(ac);
	std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector<int> : " << static_cast<float>(tVec)/CLOCKS_PER_SEC << " seconds" << std::endl;	
	std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque<int> : " << static_cast<float>(tDeq)/CLOCKS_PER_SEC << " seconds" << std::endl;
}

void	PmergeMe::_toVector(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		std::istringstream iss(av[i]);
		int		nb;
		char	rest; 
		if (iss >> nb && !(iss >> rest)) 
			this->_vec.push_back(nb);
		else
		{
			throw Error();
		}
	}
	for (size_t i = 0; i < _vec.size(); i++)
	{
		if (_vec[i] < 0)
			throw Error();
	}
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); ++it)
	{
		if (find(it + 1, _vec.end(), *it) != _vec.end())
			throw Error();
	}
}

void	PmergeMe::_printVector(std::vector<int> vec)
{
	for (unsigned int i = 0; i < vec.size(); i++)
		std::cout << ' ' << vec[i];
	std::cout << std::endl;
}

void	PmergeMe::_sortVector()
{
	//Fais des pairs en creant deux vectors (inf et sup)
	_doPairsVec();
	//Range les pairs en ordre croissant suivant les sup
	// _orderPairsVec();
	// std::cout << "inf : ";
	// for(size_t i = 0; i < _inf.size(); i++)
	// 	std::cout << _inf[i] << ' ';
	// std::cout << "\nsup : ";
	// for(size_t i = 0; i < _sup.size(); i++)
	// 	std::cout << _sup[i] << ' ';
	// std::cout << '\n';

	_mergeSortVec(_sup, _inf);
	if (_oddNb >= 0)
		_inf.push_back(_oddNb);
	// std::cout << "inf : ";
	// for(size_t i = 0; i < _inf.size(); i++)
	// 	std::cout << _inf[i] << ' ';
	// std::cout << "\nsup : ";
	// for(size_t i = 0; i < _sup.size(); i++)
	// 	std::cout << _sup[i] << ' ';
	// std::cout << '\n';
	//Remettre tous les superieurs tries dans _vec final
	for (unsigned int i = 0; i < _sup.size(); i++)
		_vecFinal.push_back(_sup[i]);
	
	// On commence par placer indice 0
	_vecFinal.insert(_vecFinal.begin(), _inf[0]);
	if (_vecFinal.size() == size)
		return ;
	// Puis on place l'indice 1 (1er de la suite de Jacobstahl)
	std::vector<int>::iterator insertIt = std::upper_bound(_vecFinal.begin(), _vecFinal.end(), _inf[1]);
	_vecFinal.insert(insertIt, _inf[1]);
	jacob = 3;
	preJac = 1;

	low = 0;
	high = _vecFinal.size() - 1;
	mid = low + (high - low) / 2;
	_index = jacob;
	while (_vecFinal.size() != size)
	{	
		if (_index >= _inf.size() && _vecFinal.size() != size)
		{
			_index = preJac + 1;
			while (_index < _inf.size())
			{
				_doDichotomyVec();
				// std::vector<int>::iterator insertIt = std::upper_bound(_vecFinal.begin(), _vecFinal.end(), _inf[_index]);
				// _vecFinal.insert(insertIt, _inf[_index]);				
				_index++;
			}
		}
		if (_vecFinal.size() == size)
			break ;
		while (_index > preJac)
		{
			_doDichotomyVec();
			// std::vector<int>::iterator insertIt = std::upper_bound(_vecFinal.begin(), _vecFinal.end(), _inf[_index]);
			// _vecFinal.insert(insertIt, _inf[_index]);			
			_index--;
		}
		tmpJacob = jacob;
		jacob = tmpJacob + 2 * preJac;
		preJac = tmpJacob;
		_index = jacob;
	}
}

void	PmergeMe::_doPairsVec(void)
{
	//Faire les pairs
	if (_vec.size() % 2 != 0)
	{
		// _inf.push_back(_vec[_vec.size()]);
		_oddNb = _vec[_vec.size() - 1];
		// std::cout << "oddNb = " << _oddNb << std::endl;
		_vec.pop_back();
	}

	for (unsigned int i = 0; i < _vec.size(); i+=2)
	{
		if (_vec[i] < _vec[i + 1])
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
}

// void	PmergeMe::_mergeSortVec(std::vector<int> _sup, int low, int high)
// {
// 	int mid;
// 	if (low < high)
// 	{
// 		mid = (low + high) / 2;
// 		_mergeSortVec(_sup, low, mid);
// 		_mergeSortVec(_sup, mid + 1, high);

// 		merge(_sup, low, high, mid);
// 	}
// }

void	PmergeMe::_mergeSortVec(std::vector<int> &_sup, std::vector<int> &_inf)
{
	// std::cout << "Splitting : ";
	// for (size_t i = 0; i < _sup.size(); i++)
	// 	std::cout << _sup[i] << ' ';
	// std::cout << std::endl;		
	if (_sup.size() > 1)
	{
		int mid = _sup.size() / 2;

		std::vector<int> _supLeftHalf;
		_supLeftHalf.assign(_sup.begin(), _sup.begin() + mid);

		std::vector<int> _supRightHalf;
		_supRightHalf.assign(_sup.begin() + mid, _sup.end());

		std::vector<int> _infLeftHalf;
		_infLeftHalf.assign(_inf.begin(), _inf.begin() + mid);

		std::vector<int> _infRightHalf;
		_infRightHalf.assign(_inf.begin() + mid, _inf.end());

		_mergeSortVec(_supLeftHalf, _infLeftHalf);
		_mergeSortVec(_supRightHalf, _infRightHalf);

		size_t i = 0;
		size_t j = 0;
		size_t k = 0;
		while (i < _supLeftHalf.size() && j < _supRightHalf.size())
		{
			if (_supLeftHalf[i] < _supRightHalf[j])
			{
				_sup[k] = _supLeftHalf[i];
				_inf[k] = _infLeftHalf[i];
				i++;
			}
			else{
				// std::cout << "ici\n";
				_sup[k] = _supRightHalf[j];
				_inf[k] = _infRightHalf[j];			
				j++;
			}
			k++;
		}
		while (i < _supLeftHalf.size())
		{
			_sup[k] = _supLeftHalf[i];
			_inf[k] = _infLeftHalf[i];
			i++;
			k++;
		}
		while (j < _supRightHalf.size())
		{
			_sup[k] = _supRightHalf[j];
			_inf[k] = _infRightHalf[j];
			j++;
			k++;
		}
	}		
	// std::cout << "Merging : ";
	// for (size_t i = 0; i < _sup.size(); i++)
	// 	std::cout << _sup[i] << ' ';
	// std::cout << std::endl;		
}

void	PmergeMe::_orderPairsVec(void)
{
	//Trier les pairs par ordre croissant avec leur superieurs
	unsigned int i = 0;
	while (i < _sup.size())
	{
		int tmp;
		unsigned int j = i + 1;
		while (j < _sup.size())
		{
			if (_sup[i] > _sup[j])
			{
				tmp = _sup[i];
				_sup[i] = _sup[j];
				_sup[j] = tmp;

				tmp = _inf[i];
				_inf[i] = _inf[j];
				_inf[j] = tmp;
			}
			j++;
		}	
		i++;
	}
	// if (_oddNb >= 0)
	// 	_inf.push_back(_oddNb);
}

void	PmergeMe::_doDichotomyVec(void)
{
	while ((high - low) > 1)//on trie un _index par un (_index [3], _index [2])
	{
		if (_vecFinal[mid] < _inf[_index])//go moitie droite
		{
			low = mid;
			mid = low + (high - low) / 2;
		}
		else if (_vecFinal[mid] > _inf[_index])//go moitie gauche
		{
			high = mid;
			mid = low + (high - low) / 2;
		}
	}
	if (mid == 0 && (_inf[_index] < _vecFinal[mid]))
		_vecFinal.insert(_vecFinal.begin(), _inf[_index]);
	else if (mid == (_vecFinal.size() - 2) && (_inf[_index] > _vecFinal[mid]) && (_inf[_index] > _vecFinal[mid + 1]))
	{
		_vecFinal.insert(_vecFinal.begin() + mid + 2, _inf[_index]);
	}
	else
	{
		_vecFinal.insert(_vecFinal.begin() + mid + 1, _inf[_index]);
	}
	low = 0;
	high = _vecFinal.size() - 1;
	mid = low + (high - low) / 2;
}

void	PmergeMe::isSortedVec(std::vector<int> vec)
{
	for (unsigned int i = 0; i < (vec.size() - 1); i++)
	{
		if (vec[i] > vec[i + 1])
		{
			std::cout << RED "Vec not sorted :////\n" RESET;
			return ;
		}
	}
	std::cout << GREEN "Vec is sorted !\n" RESET;
}

void	PmergeMe::isSameSize(int ac)
{
	size_t size = ac - 1;

	if (_vecFinal.size() == size)
		std::cout << GREEN "Vec has same size !\n" RESET;
	else
		std::cout << RED "Vec hasn't same size\n" RESET;
	if (_deqFinal.size() == size)
		std::cout << GREEN "Deq has same size !\n" RESET;
	else
		std::cout << GREEN "Deq hasn't same size\n" RESET;
}

//--  Deque --//

void	PmergeMe::_toDeque(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		std::istringstream iss(av[i]);
		unsigned int		nb;
		char				rest; 
		if (iss >> nb && !(iss >> rest)) 
			this->_deq.push_back(nb);
		else
		{
			throw Error();
		}
	}
}

void	PmergeMe::_printDeque(std::deque<int> deq)
{
	for (unsigned int i = 0; i < deq.size(); i++)
		std::cout << ' ' << deq[i];
	std::cout << std::endl;
}

void	PmergeMe::_sortDeque()
{
	//Fais des pairs en creant deux vectors (inf et sup)
	_doPairsDeq();
	//Range les pairs en ordre croissant suivant les sup
	// _orderPairsDeq();
	_mergeSortDeq(_supd, _infd);
	if (_oddNbd >= 0)
		_infd.push_back(_oddNbd);
	//Remettre tous les superieurs tries dans _vec final
	for (unsigned int i = 0; i < _supd.size(); i++)
		_deqFinal.push_back(_supd[i]);
	
	// On commence par placer indice 0
	_deqFinal.insert(_deqFinal.begin(), _infd[0]);
	if (_deqFinal.size() == size)
		return ;
	std::deque<int>::iterator insertIt = std::upper_bound(_deqFinal.begin(), _deqFinal.end(), _infd[1]);
	_deqFinal.insert(insertIt, _infd[1]);
	jacobd = 3;
	preJacd = 1;

	lowd = 0;
	highd = _deqFinal.size() - 1;
	midd = lowd + (highd - lowd) / 2;
	_indexd = jacobd;
	while (_deqFinal.size() != size)
	{
		if (_indexd >= _infd.size() && _deqFinal.size() != size)
		{
			_indexd = preJacd + 1;
			while (_indexd < _infd.size())
			{
				_doDichotomyDeq();
				// std::deque<int>::iterator insertIt = std::upper_bound(_deqFinal.begin(), _deqFinal.end(), _infd[_indexd]);
				// _deqFinal.insert(insertIt, _infd[_indexd]);
				_indexd++;
			}
		}
		if (_deqFinal.size() == size)
			break;
		while (_indexd > preJacd)
		{
			_doDichotomyDeq();
			// std::deque<int>::iterator insertIt = std::upper_bound(_deqFinal.begin(), _deqFinal.end(), _infd[_indexd]);
			// _deqFinal.insert(insertIt, _infd[_indexd]);			
			_indexd--;
		}
		tmpJacobd = jacobd;
		jacobd = tmpJacobd + 2 * preJacd;
		preJacd = tmpJacobd;
		_indexd = jacobd;

	}
}

void	PmergeMe::_doPairsDeq(void)
{
	//Faire les pairs
	if (_deq.size() % 2 != 0)
	{
		_oddNbd = _deq[_deq.size() - 1];
		_deq.pop_back();
	}
	for (unsigned int i = 0; i < _deq.size(); i+=2)
	{
		if (_deq[i] <= _deq[i + 1])
		{
			_infd.push_back(_deq[i]);
			_supd.push_back(_deq[i + 1]);
		}
		else
		{
			_infd.push_back(_deq[i + 1]);
			_supd.push_back(_deq[i]);
		}
	}
}

void	PmergeMe::_orderPairsDeq(void)
{
	//Trier les pairs par ordre croissant avec leur superieurs
	// for (unsigned int i = 0; i < (_sup.size() - 1); i++)
	unsigned int i = 0;
	while (i < (_supd.size() - 1))
	{
		int tmp;
		unsigned int j = i + 1;
		while (j < _supd.size())
		{
			if (_supd[i] > _supd[j])
			{
				tmp = _supd[i];
				_supd[i] = _supd[j];
				_supd[j] = tmp;

				tmp = _infd[i];
				_infd[i] = _infd[j];
				_infd[j] = tmp;
			}
			j++;
		}	
		i++;
	}

	if (_oddNbd >= 0)
		_infd.push_back(_oddNbd);
}

void	PmergeMe::_mergeSortDeq(std::deque<int> &_sup, std::deque<int> &_inf)
{
	// std::cout << "Splitting : ";
	// for (size_t i = 0; i < _sup.size(); i++)
	// 	std::cout << _sup[i] << ' ';
	// std::cout << std::endl;		
	if (_sup.size() > 1)
	{
		int mid = _sup.size() / 2;

		std::deque<int> _supLeftHalf;
		_supLeftHalf.assign(_sup.begin(), _sup.begin() + mid);

		std::deque<int> _supRightHalf;
		_supRightHalf.assign(_sup.begin() + mid, _sup.end());

		std::deque<int> _infLeftHalf;
		_infLeftHalf.assign(_inf.begin(), _inf.begin() + mid);

		std::deque<int> _infRightHalf;
		_infRightHalf.assign(_inf.begin() + mid, _inf.end());

		_mergeSortDeq(_supLeftHalf, _infLeftHalf);
		_mergeSortDeq(_supRightHalf, _infRightHalf);

		size_t i = 0;
		size_t j = 0;
		size_t k = 0;
		while (i < _supLeftHalf.size() && j < _supRightHalf.size())
		{
			if (_supLeftHalf[i] < _supRightHalf[j])
			{
				_sup[k] = _supLeftHalf[i];
				_inf[k] = _infLeftHalf[i];
				i++;
			}
			else{
				// std::cout << "ici\n";
				_sup[k] = _supRightHalf[j];
				_inf[k] = _infRightHalf[j];			
				j++;
			}
			k++;
		}
		while (i < _supLeftHalf.size())
		{
			_sup[k] = _supLeftHalf[i];
			_inf[k] = _infLeftHalf[i];
			i++;
			k++;
		}
		while (j < _supRightHalf.size())
		{
			_sup[k] = _supRightHalf[j];
			_inf[k] = _infRightHalf[j];
			j++;
			k++;
		}
	
	}		
	// std::cout << "Merging : ";
	// for (size_t i = 0; i < _sup.size(); i++)
	// 	std::cout << _sup[i] << ' ';
	// std::cout << std::endl;		
}

void	PmergeMe::_doDichotomyDeq(void)
{
	while ((highd - lowd) > 1)//on trie un _index par un (_index [3], _index [2])
	{
		if (_deqFinal[midd] < _infd[_indexd])//go moitie droite
		{
			lowd = midd;
			midd = lowd + (highd - lowd) / 2;
		}
		else if (_deqFinal[midd] > _infd[_indexd])//go moitie gauche
		{
			highd = midd;
			midd = lowd + (highd - lowd) / 2;
		}
	}
	if (midd == 0 && (_infd[_indexd] < _deqFinal[midd]))
		_deqFinal.insert(_deqFinal.begin(), _infd[_indexd]);
	else if (midd == (_deqFinal.size() - 2) && (_infd[_indexd] > _deqFinal[midd]) && (_infd[_indexd] > _deqFinal[midd + 1]))
	{
		_deqFinal.insert(_deqFinal.begin() + midd + 2, _infd[_indexd]);
	}
	else
	{
		_deqFinal.insert(_deqFinal.begin() + midd + 1, _infd[_indexd]);
	}
	lowd = 0;
	highd = _deqFinal.size() - 1;
	midd = lowd + (highd - lowd) / 2;
}

void	PmergeMe::isSortedDeq(std::deque<int> deq)
{
	for (unsigned int i = 0; i < (deq.size() - 1); i++)
	{
		if (deq[i] > deq[i + 1])
		{
			std::cout << RED "Deq not sorted :////\n" RESET;
			return ;
		}
	}
	std::cout << GREEN "Deq is sorted !\n" RESET;
}