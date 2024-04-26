#ifndef BASE_HPP
#define	BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

// #include <A.hpp>
// #include <B.hpp>
// #include <C.hpp>

class Base
{
	private:

	public:
		Base(void);
		virtual ~Base(void);

		Base *	generate(void);
		void	identify(Base* p);
		void	identify(Base& p);
};

#endif