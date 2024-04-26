#include "../include/Serializer.hpp"

Serializer::Serializer(void)
{
	return ;
}

Serializer::Serializer(Serializer const & src)
{
	*this = src;
	return ;
}

Serializer::~Serializer()
{
	return ;
}

Serializer  &Serializer::operator=(Serializer const & src)
{
	if (this != &src)
		*this = src;
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)// prend un pointeur et le converti en un int non signe
{
	uintptr_t value;
	
	value = reinterpret_cast<uintptr_t>(ptr);
	return value;
}


Data* Serializer::deserialize(uintptr_t raw)// prend un int non signe et le converti en pointeur vers Data
{
	Data *ptr;

	ptr = reinterpret_cast<Data *>(raw);
	return (ptr);
}