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
	//ajouter un checking des valeurs entrees
	_toVector(ac, av);
	std::cout << "Before:	";//changer de place
	_printVector(this->_vec);//changer de place
	_sortVector();
	std::cout << "After:	";
	_printVector(this->_vecFinal);
	isSortedVec(_vecFinal);

	_toDeque(ac, av);
	_sortDeque();
	isSortedDeq(_deqFinal);

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
	//Fais des pairs en creant deux vectors (inf et sup)
	_doPairsVec();
	//Range les pairs en ordre croissant suivant les sup
	_orderPairsVec();

	//Remettre tous les superieurs tries dans _vec final
	for (unsigned int i = 0; i < _sup.size(); i++)
		_vecFinal.push_back(_sup[i]);
	
	// std::cout << "vecF : ";
	// for (unsigned int i = 0; i < _vecFinal.size(); i++)
	// 	std::cout << '	' << _vecFinal[i];
	// std::cout << std::endl;	

	//On cree le vector _pos avec les indices corresponds inf -> vecFinal
	//inf2 inf3 inf4 inf5 inf6 inf7 infn
	//[2]  [3]  [4]  [5]  [6]  [7]  [n] dans vecFinal
	// for (unsigned int i = 1; i < _inf.size(); i++)
	// 	_pos.push_back(i + 1);

	// std::cout << "_pos : ";
	// for (unsigned int i = 0; i < _pos.size(); i++)
	// 	std::cout << '	' << _pos[i];
	// std::cout << std::endl;	
	
	// On commence par placer indice 1
	_vecFinal.insert(_vecFinal.begin(), _inf[1 - 1]);

	preJacob = 1;
	ppreJacob = 1;
	tmpJacob = preJacob;// = 1
	preJacob = tmpJacob + 2 * ppreJacob - 1;// 1 + (2 * 1) - 1 = 2
	ppreJacob = tmpJacob - 1;// = 0

	// std::cout << "_vecFinal : ";
	// for (unsigned int i = 0; i < _vecFinal.size(); i++)
		// std::cout << '	' << _vecFinal[i];	
	// std::cout << "\nsize = " << _vecFinal.size() << std::endl;

	// std::cout << "pre = " << preJacob << " ppre = " << ppreJacob << std::endl;

	low = 0;
	high = _vecFinal.size() - 1;
	// high = _pos[preJacob - 1];//****
	// std::cout << "_pos[preJacob - 1] = "<< _pos[preJacob - 1] << std::endl;
	mid = low + (high - low) / 2;
	_index = preJacob;
	while (_index < _inf.size())//on remet a jour la valeur de Jacob
	{
		while (_index > ppreJacob)//on trie les _index entre preJacob et ppreJacob _index[3] _index[2]
		{
			_doDichotomyVec();
			_index--;
		}
		preJacob++;//revenir aux vraies valeur de la suite Jacobstahle car on a fait -1 pour index
		ppreJacob++;
		tmpJacob = preJacob;
		preJacob = tmpJacob + 2 * ppreJacob - 1;
		ppreJacob = tmpJacob - 1;		
		_index = preJacob;
		if (_index >= _inf.size() && _vecFinal.size() != _vec.size())
		{
			_index = ppreJacob + 1;
			while (_index < _inf.size())
			{
				_doDichotomyVec();
				_index++;
			}
		}

		// std::cout << "pre = " << preJacob << " ppre = " << ppreJacob << " _index = " << _index << std::endl;
	}
	// std::cout << "_vecFinal :: ";
	// for (unsigned int i = 0; i < _vecFinal.size(); i++)
	// 	std::cout << '	' << _vecFinal[i];	
	// std::cout << "\nsize = " << _vecFinal.size() << std::endl;
}

void	PmergeMe::_doPairsVec(void)
{
	//Faire les pairs
	// std::cout << "size = " << _vec.size() << std::endl;
	if (_vec.size() % 2 != 0)
	{
		// _inf.push_back(_vec[_vec.size()]);
		_oddNb = _vec[_vec.size() - 1];
		// std::cout << "oddNb = " << _oddNb << std::endl;
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

	// std::cout << "inf : ";
	// for (unsigned int i = 0; i < _inf.size(); i++)
	// 	std::cout << '	' << _inf[i];
	// std::cout << std::endl;

	// std::cout << "sup : ";
	// for (unsigned int i = 0; i < _sup.size(); i++)
	// 	std::cout << '	' << _sup[i];
	// std::cout << std::endl;
}

void	PmergeMe::_orderPairsVec(void)
{
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
	// std::cout << "inf : ";
	// for (unsigned int i = 0; i < _inf.size(); i++)
	// 	std::cout << '	' << _inf[i];
	// std::cout << std::endl;

	// std::cout << "sup : ";
	// for (unsigned int i = 0; i < _sup.size(); i++)
	// 	std::cout << '	' << _sup[i];
	// std::cout << std::endl;
}

void	PmergeMe::_doDichotomyVec(void)
{
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
		// std::cout << "low = " << low << std::endl;
		// std::cout << "high = " << high << std::endl;
		// std::cout << "mid = " << mid << std::endl;
	}
	// std::cout << "_inf : ";
	// for (unsigned int i = 0; i < _inf.size(); i++)
	// 	std::cout << '	' << _inf[i];	
	// std::cout << "\nsize = " << _inf.size() << std::endl;

	// std::cout << "_vecFinal : ";
	// for (unsigned int i = 0; i < _vecFinal.size(); i++)
	// 	std::cout << '	' << _vecFinal[i];	
	// std::cout << "\nsize = " << _vecFinal.size() << std::endl;
	
	// std::cout << "insert=" << _inf[_index] << " _vecFinal[mid]=" << _vecFinal[mid] << "\n";
	// std::cout << "vecFinal size = " << _vecFinal.size() << "\n";
	if (mid == 0 && (_inf[_index] < _vecFinal[mid]))
		_vecFinal.insert(_vecFinal.begin(), _inf[_index]);
	else if (mid == (_vecFinal.size() - 2) && (_inf[_index] > _vecFinal[mid]) && (_inf[_index] > _vecFinal[mid + 1]))
	{
		// std::cout << "icii\n";
		_vecFinal.insert(_vecFinal.begin() + mid + 2, _inf[_index]);
	}
	else
	{
		// std::cout << "ici\n";
		_vecFinal.insert(_vecFinal.begin() + mid + 1, _inf[_index]);
	}
	low = 0;
	high = _vecFinal.size() - 1;//
	mid = low + (high - low) / 2;
}

void	PmergeMe::isSortedVec(std::vector<unsigned int> vec)
{
	for (unsigned int i = 0; i < (vec.size() - 1); i++)
	{
		if (vec[i] > vec[i + 1])
		{
			std::cout << "Vec not sorted :////\n";
			return ;
		}
	}
	std::cout << "Vec is sorted !\n";
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

void	PmergeMe::_printDeque(std::deque<unsigned int> deq)
{
	// for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	// 	std::cout << ' ' << *it;

	for (unsigned int i = 0; i < deq.size(); i++)
		std::cout << ' ' << deq[i];
	std::cout << std::endl;
}

void	PmergeMe::_sortDeque()
{
	//ajouter le temps chronometre
	//Fais des pairs en creant deux vectors (inf et sup)
	_doPairsDeq();
	//Range les pairs en ordre croissant suivant les sup
	_orderPairsDeq();

	//Remettre tous les superieurs tries dans _vec final
	for (unsigned int i = 0; i < _supd.size(); i++)
		_deqFinal.push_back(_supd[i]);
	
	// std::cout << "vecF : ";
	// for (unsigned int i = 0; i < _vecFinal.size(); i++)
	// 	std::cout << '	' << _vecFinal[i];
	// std::cout << std::endl;	

	//On cree le vector _pos avec les indices corresponds inf -> vecFinal
	//inf2 inf3 inf4 inf5 inf6 inf7 infn
	//[2]  [3]  [4]  [5]  [6]  [7]  [n] dans vecFinal
	// for (unsigned int i = 1; i < _inf.size(); i++)
	// 	_pos.push_back(i + 1);

	// std::cout << "_pos : ";
	// for (unsigned int i = 0; i < _pos.size(); i++)
	// 	std::cout << '	' << _pos[i];
	// std::cout << std::endl;	
	
	// On commence par placer indice 1
	_deqFinal.insert(_deqFinal.begin(), _infd[1 - 1]);

	preJacobd = 1;
	ppreJacobd = 1;
	tmpJacobd = preJacobd;// = 1
	preJacobd = tmpJacobd + 2 * ppreJacobd - 1;// 1 + (2 * 1) - 1 = 2
	ppreJacobd = tmpJacobd - 1;// = 0

	// std::cout << "_vecFinal : ";
	// for (unsigned int i = 0; i < _vecFinal.size(); i++)
		// std::cout << '	' << _vecFinal[i];	
	// std::cout << "\nsize = " << _vecFinal.size() << std::endl;

	// std::cout << "pre = " << preJacob << " ppre = " << ppreJacob << std::endl;

	lowd = 0;
	highd = _deqFinal.size() - 1;
	// high = _pos[preJacob - 1];//****
	// std::cout << "_pos[preJacob - 1] = "<< _pos[preJacob - 1] << std::endl;
	midd = lowd + (highd - lowd) / 2;
	_indexd = preJacobd;
	while (_indexd < _infd.size())//on remet a jour la valeur de Jacob
	{
		while (_indexd > ppreJacobd)//on trie les _index entre preJacob et ppreJacob _index[3] _index[2]
		{
			_doDichotomyDeq();
			_indexd--;
		}
		preJacobd++;//revenir aux vraies valeur de la suite Jacobstahle car on a fait -1 pour index
		ppreJacobd++;
		tmpJacobd = preJacobd;
		preJacobd = tmpJacobd + 2 * ppreJacobd - 1;
		ppreJacobd = tmpJacobd - 1;		
		_indexd = preJacobd;
		if (_indexd >= _infd.size() && _deqFinal.size() != _deq.size())
		{
			_indexd = ppreJacobd + 1;
			while (_indexd < _infd.size())
			{
				_doDichotomyDeq();
				_indexd++;
			}
		}

		// std::cout << "pre = " << preJacob << " ppre = " << ppreJacob << " _index = " << _index << std::endl;
	}
	// std::cout << "_vecFinal :: ";
	// for (unsigned int i = 0; i < _vecFinal.size(); i++)
	// 	std::cout << '	' << _vecFinal[i];	
	// std::cout << "\nsize = " << _vecFinal.size() << std::endl;
}

void	PmergeMe::_doPairsDeq(void)
{
	//Faire les pairs
	// std::cout << "size = " << _vec.size() << std::endl;
	if (_deq.size() % 2 != 0)
	{
		// _inf.push_back(_vec[_vec.size()]);
		_oddNbd = _deq[_deq.size() - 1];
		// std::cout << "oddNb = " << _oddNb << std::endl;
		_deq.pop_back();
	}
	// std::cout << "vec pop back :";
	// for (unsigned int i = 0; i < _vec.size(); i++)
	// 	std::cout << ' ' << _vec[i]; std::cout << std::endl;

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

	// std::cout << "inf : ";
	// for (unsigned int i = 0; i < _inf.size(); i++)
	// 	std::cout << '	' << _inf[i];
	// std::cout << std::endl;

	// std::cout << "sup : ";
	// for (unsigned int i = 0; i < _sup.size(); i++)
	// 	std::cout << '	' << _sup[i];
	// std::cout << std::endl;
}

void	PmergeMe::_orderPairsDeq(void)
{
	//Trier les pairs par ordre croissant avec leur superieurs
	// for (unsigned int i = 0; i < (_sup.size() - 1); i++)
	unsigned int i = 0;
	while (i < (_supd.size() - 1))
	{
		int tmp;
		if (_supd[i] > _supd[i + 1])
		{
			tmp = _supd[i + 1];
			_supd[i + 1] = _supd[i];
			_supd[i] = tmp;
			tmp = _infd[i + 1];
			_infd[i + 1] = _infd[i];
			_infd[i] = tmp;
			i = 0;
		}
		else
			i++;
	}// a changer

	if (_oddNbd >= 0)
		_infd.push_back(_oddNbd);
	// std::cout << "inf : ";
	// for (unsigned int i = 0; i < _inf.size(); i++)
	// 	std::cout << '	' << _inf[i];
	// std::cout << std::endl;

	// std::cout << "sup : ";
	// for (unsigned int i = 0; i < _sup.size(); i++)
	// 	std::cout << '	' << _sup[i];
	// std::cout << std::endl;
}

void	PmergeMe::_doDichotomyDeq(void)
{
	while ((highd - lowd) > 1)//on trie un _index par un (_index [3], _index [2])
	{
		if (_deqFinal[midd] < _infd[_indexd])//go moitie droite
		{
			lowd = midd;
			// high = high;
			midd = lowd + (highd - lowd) / 2;
		}
		else if (_deqFinal[midd] > _infd[_indexd])//go moitie gauche
		{
			// low = low;
			highd = midd;
			midd = lowd + (highd - lowd) / 2;
		}
		// std::cout << "low = " << low << std::endl;
		// std::cout << "high = " << high << std::endl;
		// std::cout << "mid = " << mid << std::endl;
	}
	// std::cout << "_inf : ";
	// for (unsigned int i = 0; i < _inf.size(); i++)
	// 	std::cout << '	' << _inf[i];	
	// std::cout << "\nsize = " << _inf.size() << std::endl;

	// std::cout << "_vecFinal : ";
	// for (unsigned int i = 0; i < _vecFinal.size(); i++)
	// 	std::cout << '	' << _vecFinal[i];	
	// std::cout << "\nsize = " << _vecFinal.size() << std::endl;
	
	// std::cout << "insert=" << _inf[_index] << " _vecFinal[mid]=" << _vecFinal[mid] << "\n";
	// std::cout << "vecFinal size = " << _vecFinal.size() << "\n";
	if (midd == 0 && (_infd[_indexd] < _deqFinal[midd]))
		_deqFinal.insert(_deqFinal.begin(), _infd[_indexd]);
	else if (midd == (_deqFinal.size() - 2) && (_infd[_indexd] > _deqFinal[midd]) && (_infd[_indexd] > _deqFinal[midd + 1]))
	{
		// std::cout << "icii\n";
		_deqFinal.insert(_deqFinal.begin() + midd + 2, _infd[_indexd]);
	}
	else
	{
		// std::cout << "ici\n";
		_deqFinal.insert(_deqFinal.begin() + midd + 1, _infd[_indexd]);
	}
	lowd = 0;
	highd = _deqFinal.size() - 1;//
	midd = lowd + (highd - lowd) / 2;
}

void	PmergeMe::isSortedDeq(std::deque<unsigned int> deq)
{
	for (unsigned int i = 0; i < (deq.size() - 1); i++)
	{
		if (deq[i] > deq[i + 1])
		{
			std::cout << "Deq not sorted :////\n";
			return ;
		}
	}
	std::cout << "Deq is sorted !\n";
}