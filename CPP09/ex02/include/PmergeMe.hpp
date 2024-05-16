#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <iterator>

class PmergeMe
{
	private :
		std::vector<unsigned int> _vec;
		std::vector<unsigned int> _vecFinal;
		std::vector<unsigned int> _inf;
		std::vector<unsigned int> _sup;

		int		_oddNb;
		// int		_insert;
		unsigned int	_index;

		void	_toVector(int ac, char **av);
		void	_printVector(std::vector<unsigned int> vec);
		void	_sortVector();
		unsigned int	_doDichotomy(unsigned int low, unsigned int high, unsigned int mid);
		// void	_sortDeque();
	public :
		PmergeMe(void);
		PmergeMe(PmergeMe const & src);
		~PmergeMe(void);
		PmergeMe & operator=(PmergeMe const & src);

		void	MergeInsertion(int ac, char **av);

		void	isSortedVec(std::vector<unsigned int> vec);
		


	class Error : public std::exception
	{
		public : virtual const char *what() const throw(){
			return "Error";
		}
	};
};

#endif