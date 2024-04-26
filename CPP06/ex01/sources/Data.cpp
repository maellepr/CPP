#include "../include/Data.hpp"

Data::Data(void)
{
	return ;
}

Data::Data(Data const & src)
{
	if (this != &src)
		*this = src;
}

Data::~Data(void)
{
	return ;
}

Data	&Data::operator=(Data const & src)
{
	if (this != &src)
		*this = src;
	return (*this);
}
