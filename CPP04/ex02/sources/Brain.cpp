#include "../include/Brain.hpp"

/**** Default constructor ****/
Brain::Brain(void)
{
	std::cout << PURPLE << ITAL << "Brain class : " << RESET << "default constructor called" << std::endl;
	return ;
}

/**** Copy constructor ****/
Brain::Brain(Brain const & src) 
{
	std::cout << PURPLE << ITAL << "Brain class : " << RESET << "copy constructor called" << std::endl;
	*this = src;
	return ;
}

/**** Destructor ****/
Brain::~Brain(void)
{
	std::cout << PURPLE << ITAL << "Brain class : " << RESET "Destructor called" << std::endl;
	return ;
}

/**** Assignement operator ****/
Brain &	Brain::operator=(Brain const & src)
{
	std::cout << "Brain class : copy assignment operator called" << std::endl;
	// if (this != &src) {
		for (int i = 0; i < nb_ideas; i++)
			this->_ideas[i] = src._ideas[i];
	// }
	return (*this);
}

/**** Setter ****/
void	Brain::setIdeas(int i, std::string const & idea)
{
	if (i >= 0 && i <= 100)
		this->_ideas[i] = idea;
	else
		std::cout << "The index has to be between 0 and 100" << std::endl;
	return ;
}
/**** Getter ****/
std::string const	Brain::getIdea(int i) const
{
	if (i >= 0 && i <= 100)
		return _ideas[i];
	std::cout << "The index has to be between 0 and 100" << std::endl;
	return NULL;
}
