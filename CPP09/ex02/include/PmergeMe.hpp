#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <deque>
#include <iterator>
#include <algorithm>

class PmergeMe
{
	private :
		std::vector<unsigned int> _vec;
		std::vector<unsigned int> _vecFinal;
		std::vector<unsigned int> _inf;
		std::vector<unsigned int> _sup;

		std::deque<unsigned int> _deq;
		std::deque<unsigned int> _deqFinal;
		std::deque<unsigned int> _infd;
		std::deque<unsigned int> _supd;

		// std::vector<unsigned int> _pos;

		int		_oddNb;
		// int		_insert;
		unsigned int	_index;
		unsigned int	low;
		unsigned int	high;
		unsigned int	mid;
		unsigned int	preJacob;
		unsigned int	ppreJacob;
		unsigned int	tmpJacob;

		int		_oddNbd;
		unsigned int	_indexd;
		unsigned int	lowd;
		unsigned int	highd;
		unsigned int	midd;
		unsigned int	preJacobd;
		unsigned int	ppreJacobd;
		unsigned int	tmpJacobd;

		void	_toVector(int ac, char **av);
		void	_printVector(std::vector<unsigned int> vec);
		void	_sortVector(void);
		void	_doPairsVec(void);
		void	_orderPairsVec(void);		
		void	_doDichotomyVec(void);

		void	_toDeque(int ac, char **av);
		void	_printDeque(std::deque<unsigned int> deq);
		void	_sortDeque(void);
		void	_doPairsDeq(void);
		void	_orderPairsDeq(void);
		void	_doDichotomyDeq(void);

		// void	_sortDeque();
	public :
		PmergeMe(void);
		PmergeMe(PmergeMe const & src);
		~PmergeMe(void);
		PmergeMe & operator=(PmergeMe const & src);

		void	MergeInsertion(int ac, char **av);

		void	isSortedVec(std::vector<unsigned int> vec);
		void	isSortedDeq(std::deque<unsigned int> vec);


	class Error : public std::exception
	{
		public : virtual const char *what() const throw(){
			return "Error";
		}
	};
};

#endif