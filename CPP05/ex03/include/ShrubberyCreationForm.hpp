#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public :
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & src);
		
		void	doExecution(void) const;

	protected :
		static const int			_gradeRequiredToSign = 145;
		static const int			_gradeRequiredToExecute = 137;
		std::string					_target;
		static const std::string	_shrubbery;
		static const std::string	_shrubbery2;

};

#endif