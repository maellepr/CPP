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
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	private :

	public :
		MutantStack(void){ return; }
		MutantStack(MutantStack const & src){ *this = src; }
		~MutantStack(void){ return ;}
		MutantStack & operator=(MutantStack const & src)
		{ 
			if (this != &src)
				*this = src;
			return (*this);
		}
		
		typedef typename MutantStack<T>::stack::container_type::iterator iterator;
		iterator begin() {return this->c.begin();}
		iterator end() {return this->c.end();}

		typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin() {return this->c.rbegin();}
		reverse_iterator rend() {return this->c.rend();}
};

#endif