#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <map>

class BitcoinExchange
{
	private :
		std::map<std::string, float> _data;

		void	_checkLine(const std::string line) const;
		void	_checkDate(const std::string date) const;
		void	_checkPipe(const std::string pipe) const;
		float	_checkValue(const std::string value) const;
	public : 
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const & src);
		~BitcoinExchange(void);

		BitcoinExchange & operator=(BitcoinExchange const & src);

		int		readInputFile(std::string file);
		void	initDatabase(void);
		// int	printData(void);
	

/* Exception for date */
		class BadInput : public std::exception
		{
			public :
				virtual const char *what() const throw(){
					return "bad input.";}
		};
		class DateBelow : public std::exception
		{
			public :
				virtual const char *what() const throw(){
					return "date below available database dates";}
		};
		class DateAbove : public std::exception
		{
			public : 
				virtual const char *what() const throw(){
					return "date above available database dates";}
		};
/*Exception for pipe*/		
		class WrongFormat : public std::exception
		{
			public :
				virtual const char *what() const throw(){
					return "wrong format.";}
		};

/*Exception for value*/
		class WrongValueFormat : public std::exception
		{
			public :
				virtual const char *what() const throw(){
					return "wrong value format.";}
		};
		class NotPositiveNb : public std::exception
		{
			public :
				virtual const char *what() const throw(){
					return "not a positive number.";}
		};
		class TooLargeNb : public std::exception
		{
			public :
				virtual const char *what() const throw(){
					return "too large number.";}
		};
/*Exception for database*/
		class ErrorDatabase : public std::exception
		{
			public :
				virtual const char *what() const throw(){
					return "Error : could not open database.";}
		};
};

// strftime
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