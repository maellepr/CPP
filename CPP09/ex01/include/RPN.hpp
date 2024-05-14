#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <stack>

class RPN
{
	private :
		
	public :
		RPN(void);
		RPN(RPN const & src);
		~RPN(void);
		RPN & operator=(RPN const & src);

		void	checkError(const std::string line) const;
		void	doCalcul(const std::string line) const;

	class Error : public std::exception
	{
		public : virtual const char *what() const throw(){
			return "Error";}
	};
};

#endif