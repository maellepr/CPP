#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"

Base::Base(void)
{
	return ;
}

Base::~Base(void)
{
	return ;
}

/* Instancie aleatoirement A, B ou C et retourne l'instance comme un pointeur sur Base */
Base *	Base::generate(void)
{
	Base	*base;

	srand (time(NULL));
	int nb = (rand() % 4);

	std::cout << "nb = " << nb << std::endl;

	if (nb == 1)
		base = new A();
	else if (nb == 2)
		base = new B();
	else
		base = new C();
	return (base);
}

/* Ecrit le type actuel de l'objet sur lequel pointe p: A, B ou C */
void	Base::identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Class A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Class B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Class C" << std::endl;
	return ;
}

/* Ecrit le type actuel de l'objet sur lequel pointe p: A, B, C sans utiliser les pointeurs */
void	Base::identify(Base& p)
{
	try 
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Class A" << std::endl;
	}
	catch(std::exception const & e){}

	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "Class B" << std::endl;
	}
	catch(std::exception const & e){}

	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "Class C" << std::endl;
	}
	catch(std::exception const & e){}
	return ;
}