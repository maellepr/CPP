#ifndef SPAN_HPP
#define SPAN_HPP

#define BOLD	"\e[1m"
#define RESET	"\e[0m"

#include <iostream>
#include <string>

#include <iterator> 
#include <vector>
#include <list>
#include <algorithm>

class Span
{
	private:
		unsigned int		N;
		std::vector<int>	tab;
	public:
		Span(void);
		Span(unsigned int N);
		Span(Span const & src);
		Span & operator=(Span const & src);
		~Span();

		void	addNumber(int nb);

		void	addNumberRange(std::vector<int> vector);
		int		shortestSpan();
		int		longestSpan();


		class	ArrayIsFull : public std::exception
		{
			public :
					virtual const char* what() const throw();
		};
		class	NoDistanceFound : public std::exception
		{
			public : 
					virtual const char* what() const throw();
		};

		void	PrintSpan(void);
};

#endif