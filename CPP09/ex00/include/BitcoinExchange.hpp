#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
// #include <istream>
#include <sstream>
#include <fstream>
#include <map>

class BitcoinExchange
{
	private :
		std::map<std::string, float> _data;

		void	_checkDate(const std::string date) const;
	public : 
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const & src);
		~BitcoinExchange(void);

		BitcoinExchange & operator=(BitcoinExchange const & src);

		int	readInputFile(std::string file);
		// int	printData(void);
	
		class WrongDateFormat : public std::exception
		{
			public :
				virtual const char *what() const throw()
				{
					return "Wrong date format";
				}
		};
	
};

// strptime
// stl algorithm lower bound 

#endif

// #ifndef SPAN_HPP
// #define SPAN_HPP

// #define BOLD	"\e[1m"
// #define RESET	"\e[0m"

// #include <iostream>
// #include <string>

// #include <iterator> 
// #include <vector>
// #include <list>
// #include <algorithm>

// class Span
// {
// 	private:
// 		unsigned int		N;
// 		std::vector<int>	tab;
// 	public:
// 		Span(void);
// 		Span(unsigned int N);
// 		Span(Span const & src);
// 		Span & operator=(Span const & src);
// 		~Span();

// 		void	addNumber(int nb);

// 		void	addNumberRange(std::vector<int> vector);
// 		int		shortestSpan();
// 		int		longestSpan();


// 		class	ArrayIsFull : public std::exception
// 		{
// 			public :
// 					virtual const char* what() const throw();
// 		};
// 		class	NoDistanceFound : public std::exception
// 		{
// 			public : 
// 					virtual const char* what() const throw();
// 		};

// 		void	PrintSpan(void);
// };

// #endif