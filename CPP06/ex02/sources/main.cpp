#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"

int main(void)
{
	Base	base1;
	Base	*base2;

	base2 = base1.generate();
	base1.identify(base2);
	base1.identify(*base2);

	delete base2;

}