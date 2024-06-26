#include "../include/Array.hpp"

int main(void)
{	
	try 
	{
		Array<int> tabEmpty;
		
		std::cout << BOLD << "-- Creation et init tableau de taille 5 --" << RESET << std::endl;
		unsigned int size = 5;
		Array <int> tab(size);
		for (unsigned int i = 0; i < size; i++)
		{
			tab[i] = i;
			std::cout << tab[i] << " ";
		}	

		std::cout << std::endl;
		std::cout << "Array size : " << tab.size() << std::endl;

		std::cout << BOLD << "-- Make a copy with copy constructor --" << RESET << std::endl;
		Array <int> tabCopy(tab);
		for (unsigned int i = 0; i < size; i++)
			std::cout << tabCopy[i] << " ";
		std::cout << std::endl;
		std::cout << "Array size : " << tabCopy.size() << std::endl;

		std::cout << BOLD << "-- Make a copy using assignement operator --" << RESET << std::endl;
		const Array <int> tabCopy2 = tab;
		for (unsigned int i = 0; i < size; i++)
			std::cout << tabCopy2[i] << " ";

		std::cout << std::endl;
		std::cout << "Array size : " << tabCopy2.size() << std::endl;

		std::cout << BOLD << "-- Make modifications --" << RESET << std::endl;
		tabCopy[0] = 8;
		tabCopy[1] = 7;
		tabCopy[2] = 6;
		tabCopy[3] = 5;
		tabCopy[4] = 4;

		std::cout << "tab :		";
		for (unsigned int i = 0; i < size; i++)
			std::cout << tab[i] << " ";
		std::cout << std::endl;

		std::cout << "tabCopy :	";
		for (unsigned int i = 0; i < size; i++)
			std::cout << tabCopy[i] << " ";
		std::cout << std::endl;

		std::cout << BOLD << "-- Index out of bound --" << RESET << std::endl;
		std::cout << tab[5] << std::endl;	
	}
	catch(const std::exception & e)
	{
			std::cerr << e.what() << std::endl;
	}
	return 0;
}