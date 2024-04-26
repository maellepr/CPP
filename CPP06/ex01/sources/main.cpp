#include "../include/Serializer.hpp"
#include "../include/Data.hpp"

int main(void)
{
	Data		*ptr1;
	Data		*ptr2;
	uintptr_t	nb_raw;

	ptr1 = new Data();
	ptr1->nb = 10;
	std::cout << "ptr1 = " << ptr1 << std::endl;
	std::cout << "ptr1->nb = " << ptr1->nb << std::endl;
	nb_raw = Serializer::serialize(ptr1);
	std::cout << "nb_raw = " << nb_raw << std::endl;
	ptr2 = Serializer::deserialize(nb_raw);
	std::cout << "ptr2 = " << ptr2 << std::endl;
	std::cout << "ptr2->nb = " << ptr2->nb << std::endl;

	delete ptr1;
}