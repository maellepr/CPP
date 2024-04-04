#include "Fixed.hpp"

/**** Default constructor ****/
Fixed::Fixed(void) : _nbFixedPt(0)
{
	// std::cout << "Default constructor called" << std::endl;
	return ;
}

/**** Copy constructor ****/
Fixed::Fixed(Fixed const & src)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

// convertie un int constant en virgule fixe
Fixed::Fixed(int const nb): _nbFixedPt(nb << _nbBits)
{
	// std::cout << "Int constructor called" << std::endl;
	return ;
}

// convertie un float constant en virgule fixe
Fixed::Fixed(float const f): _nbFixedPt(roundf(f * (1 << _nbBits)))
{
	// std::cout << "Float constructor called" << std::endl;
	return ;
}

/**** Destructor ****/
Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
	return ;
}

/**** Operator ****/
Fixed &	Fixed::operator=(Fixed const & src)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_nbFixedPt = src.getRawBits();
	return (*this);
}

Fixed	Fixed::operator>(Fixed const & src) const
{
	return (this->_nbFixedPt > src.getRawBits());
}

Fixed	Fixed::operator<(Fixed const & src) const
{
	return (this->_nbFixedPt < src.getRawBits());
}

Fixed	Fixed::operator>=(Fixed const & src) const
{
	return (this->_nbFixedPt >= src.getRawBits());
}

Fixed	Fixed::operator<=(Fixed const & src) const
{
	return (this->_nbFixedPt <= src.getRawBits());
}

Fixed	Fixed::operator==(Fixed const & src) const
{
	return (this->_nbFixedPt == src.getRawBits());
}

Fixed	Fixed::operator!=(Fixed const & src) const
{
	return (this->_nbFixedPt != src.getRawBits());
}

Fixed	Fixed::operator+(Fixed const & nb) const
{
	Fixed result;
	
	// result.setRawBits(this->getRawBits() + nb.getRawBits());
	result.setRawBits(_nbFixedPt + nb.getRawBits());
	// dans l'ex _nbFixedPt est a et nb est b 

	return (result);
}

Fixed	Fixed::operator-(Fixed const & nb) const
{
	Fixed result;

	result.setRawBits(_nbFixedPt - nb.getRawBits());
	return (result);
}

Fixed	Fixed::operator*(Fixed const & nb) const
{
	Fixed result;

	result.setRawBits((this->getRawBits() * nb.getRawBits()) / (1 << _nbBits));
	return (result);
}

Fixed	Fixed::operator/(Fixed const & nb) const
{
	// Fixed result;

	// result.setRawBits((this->getRawBits() / nb.getRawBits()) * (1 << _nbBits));
	// la methode ci dessus ne marche pas pour les float

	Fixed	result((float) this->getRawBits() / nb.getRawBits());
	return (result);
}

Fixed	Fixed::operator++()
{
	this->_nbFixedPt++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	this_tmp(*this);

	++(*this);
	return (this_tmp);
}

Fixed	Fixed::operator--()
{
	this->_nbFixedPt--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	this_tmp(*this);

	--(*this);
	return (this_tmp);
}

Fixed	& Fixed::min(Fixed & nb1, Fixed & nb2)
{
	if (nb1.getRawBits() < nb2.getRawBits())
		return (nb1);
	return (nb2);
}

Fixed const &Fixed::min(Fixed const & nb1, Fixed const & nb2)
{
	if (nb1.getRawBits() < nb2.getRawBits())
		return (nb1);
	return (nb2);
}

Fixed	& Fixed::max(Fixed & nb1, Fixed & nb2)
{
	if (nb1.getRawBits() > nb2.getRawBits())
		return (nb1);
	return (nb2);
}

Fixed const &	Fixed::max(Fixed const & nb1, Fixed const & nb2)
{
	if (nb1.getRawBits() > nb2.getRawBits())
		return (nb1);
	return (nb2);
}

/**** Getter ****/
int		Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_nbFixedPt);
}

/**** Setter ****/
void	Fixed::setRawBits(int const raw)
{
	// std::cout << "Setter called" << std::endl;
	this->_nbFixedPt = raw;
	return ;
}

int	Fixed::toInt(void) const
{
	//converti nb virgule fixe en nb entier
	return (this->_nbFixedPt >> Fixed::_nbBits);
}

float	Fixed::toFloat(void) const
{
	//converti nb virgule fixe en nb float
	return ((float)this->_nbFixedPt / (1 << _nbBits));
}

std::ostream &	operator<<(std::ostream & o, Fixed const & nb)
{
	o << nb.toFloat();
	return (o);
}
