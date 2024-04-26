#ifndef C_HPP
#define C_HPP

#include "Base.hpp"

class C: public Base 
{
	private:

	public:
		C(void);
		~C(void);

		static const char c = 'C';
};

#endif