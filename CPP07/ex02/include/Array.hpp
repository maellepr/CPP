#ifndef ARRAY_HPP
#define ARRAY_HPP

#define BOLD	"\e[1m"
#define DIM		"\e[2m"
#define ITAL	"\e[3m"
#define ULINE	"\e[4m"

#define	YELLOW	"\e[38;2;217;255;0m"
#define	PINK	"\e[38;2;255;0;89m"
#define PURPLE	"\e[38;2;255;0;217m"
#define	GREEN	"\e[38;2;89;255;0m"
#define	RED		"\e[38;2;255;0;0m"
#define BLUE	"\e[38;2;0;233;255m"

#define RESET	"\e[0m"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

template <typename T>
class Array
{
	public:	

		Array(void): _array(NULL), _n(0) {}
		Array(unsigned int n): _array(new T[n]), _n(n)
		{
			for (unsigned int i = 0; i < _n; i++)
				_array[i] = 0;
		}
		Array(const Array & src): _n(src._n)
		{
			if (src._array)
			{
				this->_array = new T[_n];
				for (unsigned int i = 0; i < _n; i++)
					this->_array[i] = src._array[i];
			}
			else
				_array = NULL;
		}

		Array &operator=(const Array & src)
		{
			if (this != &src)
			{
				this->_n = src._n;
				if (src._array)
				{
					if (_array)
						delete [] _array;
					this->_array = new T[_n];
					for (unsigned int i = 0; i < _n; i++)
						this->_array[i] = src._array[i];
				}
				else
					_array = NULL;
			}
			return (*this);
		}
		
		~Array(void)
		{
			if (this->_array)
				delete [] this->_array;
		}
	
		class indexOutOfBound : public std::exception
		{
			public: 
				virtual const char *what() const throw()
				{
					return "Wrong index";
				}
		};

		T &operator[](unsigned int n)
		{
			if (n < 0 || n >= this->_n)
				throw indexOutOfBound();
			return this->_array[n];
		}
		const T &operator[](unsigned int n) const
		{
			if (n < 0 || n >= this->_n)
				throw indexOutOfBound();
			return this->_array[n];
		}

		unsigned int	size(void) const 
		{
			return _n;
		}
	private:
		T *				_array;
		unsigned int	_n;
};

#endif
