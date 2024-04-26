#ifndef A_HPP
#define A_HPP

#include "Base.hpp"

class A: public Base 
{
	private:

	public:
		A(void);
		~A(void);

		static const char c = 'A';
};

#endif