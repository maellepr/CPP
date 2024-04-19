#include "../include/ShrubberyCreationForm.hpp"

/*** Default constructor ****/
ShrubberyCreationForm::ShrubberyCreationForm(void): 
AForm("ShrubberyCreationForm", this->_gradeRequiredToSign, this->_gradeRequiredToExecute), 
_target("")
{
	std::cout << BLUE << ITAL << "ShrubberyCreationForm class : " << RESET << "default constructor called" << std::endl;
	return ;
}

/**** Constructor with target initialization ****/
ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
AForm("ShrubberyCreationForm", this->_gradeRequiredToSign, this->_gradeRequiredToExecute),
_target(target)
{
	std::cout << BLUE << ITAL << "ShrubberyCreationForm class : " << RESET << "constructor called with target initialization" << std::endl;

}

/**** Copy constructor *****/
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src):
AForm(src._target, src._gradeRequiredToSign, src._gradeRequiredToExecute)
{
	std::cout << BLUE << ITAL << "ShrubberyCreationForm class : " << RESET << "copy constructor called" << std::endl;
	this->_target = src._target;
}

/**** Destructor ****/
ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << BLUE << ITAL << "ShrubberyCreationForm class : " << RESET << "destructor called" << std::endl;
}

/**** Assignement Operator ****/
ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src)
{
	std::cout << "Shrubbery class : copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_target = src._target;
	}
	return (*this);	
}

/**** Other Functions ****/
void	ShrubberyCreationForm::doExecution(void) const
{
	std::ofstream file;
	
	file.open((this->_target + "_shrubbery").c_str());
	
	if (file.is_open())
	{
		file << this->_shrubbery;
		file << this->_shrubbery2;
	}
}

std::string const ShrubberyCreationForm::_shrubbery = 
"                     . . .\n"
"                   .        .  .     ..    .\n"
"                .                 .         .  .\n"
"                                .\n"
"                               .                ..\n"
"               .          .            .              .\n"
"               .            '.,        .               .\n"
"               .              'b      *\n"
"                .              '$    #.                ..\n"
"               .    .           $:   #:               .\n"
"             ..      .  ..      *#  @):        .   . .\n"
"                          .     :@,@):   ,.**:'   .\n"
"              .      .,         :@@*: ..**'      .   .\n"
"                       '#o.    .:(@'.@*'  .\n"
"               .  .       'bq,..:,@@*'   ,*      .  .\n"
"                          ,p$q8,:@)'  .p*'      .\n"
"                   .     '  . '@@Pp@@*'    .  .\n"
"                    .  . ..    Y7'.'     .  .\n"
"                              :@):.\n"
"                             .:@:'.\n"
"                           .::(@:.\n";

std::string const ShrubberyCreationForm::_shrubbery2 = 
"\n"
"            .        +          .      .          .\n"
"     .            _        .                    .\n"
"  ,              /;-._,-.____        ,-----.__\n"
" ((        .    (_:#::_.:::. `-._   /:, /-._, `._,\n"
"  `                 /   _|`=:_::.`.);   __/ /\n"
"                      ,    `./  /:. `.   )==-'  .\n"
"    .      ., ,-=-.  ,/, +#./`   /:.  / /           .\n"
".           //:/`-' , ,/ '` ` `   ): , /_  -o\n"
"       .    /:+- - + +- : :- + + -:'  /(o-) )     .\n"
"  .      ,=':  /    ` `/` ' , , ,:' `'--.-----._/`7\n"
"   `.   (    /: /,-._` ` + '/, ,   _,--._,---:.__/\n"
"              /:  `  X` _| _,//'   .-'\n"
".               :._:`____  /:'        .            .\n"
"                    /::.  ://:'  /              +\n"
"   .                 `.:.  /:'  }      .\n"
"           .           ):_(:;   /           .\n"
"                      /:. _/ ,  |\n"
"                   . (|::.     ,`                  .\n"
"     .                |::.    {\\n"
"                      |::./  / `.\n"
"                      |:::(/    |\n"
"              O       |:::/{ }  |                  (o\n"
"               )  ___/#/::`/ (O ==._____   O, (O  /`\n"
"          ~~~w/w~~~,/` `:/,-(~`/~~~~~~~~/~o~/~/~w|/~ \n"
"     ~~~~~~~~~~~~~~~~~~~~~~~W~~~~~~~~~~~~|/~~ \n";