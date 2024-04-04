#include "../include/Fixed.hpp"

/**** Default constructor ****/
Fixed::Fixed(void) : _nbFixedPt(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

/**** Copy constructor ****/
Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

/**** Destructor ****/
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

/**** Operator ****/
Fixed &	Fixed::operator=(Fixed const & src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_nbFixedPt = src.getRawBits();
	return (*this);
}

/**** Getter ****/
int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_nbFixedPt);
}

/**** Setter ****/
void	Fixed::setRawBits(int const raw)
{
	std::cout << "Setter called" << std::endl;
	this->_nbFixedPt = raw;
	return ;
}