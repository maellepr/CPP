#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cctype>

#define	GREEN	"\e[38;2;89;255;0m"
#define	RED		"\e[38;2;255;0;0m"

#define RESET	"\e[0m"

class PmergeMe
{
	private :
		std::vector<int> _vec;
		std::vector<int> _vecFinal;
		std::vector<int> _inf;
		std::vector<int> _sup;

		std::deque<int> _deq;
		std::deque<int> _deqFinal;
		std::deque<int> _infd;
		std::deque<int> _supd;

		// std::vector<unsigned int> _pos;

		int		_oddNb;
		size_t	size;
		// int		_insert;
		unsigned int	_index;
		unsigned int	low;
		unsigned int	high;
		unsigned int	mid;
		unsigned int	jacob;
		unsigned int	preJac;
		unsigned int	tmpJacob;

		int		_oddNbd;
		unsigned int	_indexd;
		unsigned int	lowd;
		unsigned int	highd;
		unsigned int	midd;
		unsigned int	jacobd;
		unsigned int	preJacd;
		unsigned int	tmpJacobd;

		void	_toVector(int ac, char **av);
		void	_printVector(std::vector<int> vec);
		void	_sortVector(void);
		void	_doPairsVec(void);
		void	_orderPairsVec(void);
		void	_mergeSortVec(std::vector<int> &_sup, std::vector<int> &_inf);
		void	_doDichotomyVec(void);


		void	_toDeque(int ac, char **av);
		void	_printDeque(std::deque<int> deq);
		void	_sortDeque(void);
		void	_doPairsDeq(void);
		void	_orderPairsDeq(void);
		void	_mergeSortDeq(std::deque<int> &_sup, std::deque<int> &_inf);
		void	_doDichotomyDeq(void);

		// void	_sortDeque();
	public :
		PmergeMe(void);
		PmergeMe(PmergeMe const & src);
		~PmergeMe(void);
		PmergeMe & operator=(PmergeMe const & src);

		void	MergeInsertion(int ac, char **av);

		void	isSortedVec(std::vector<int> vec);
		void	isSortedDeq(std::deque<int> vec);
		void	isSameSize(int ac);


	class Error : public std::exception
	{
		public : virtual const char *what() const throw(){
			return "Error";
		}
	};
};

#endif