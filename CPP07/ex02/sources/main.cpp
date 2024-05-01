#include "../include/Array.hpp"

int main(void)
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
	Array <int> tabCopy2 = tab;
	for (unsigned int i = 0; i < size; i++)
		std::cout << tabCopy2[i] << " ";
	std::cout << std::endl;
	std::cout << "Array size : " << tabCopy2.size() << std::endl;

	std::cout << BOLD << "-- Make modifications --" << RESET << std::endl;
	tabCopy[0] = 34;

	tabCopy2[0] = 8;
	tabCopy2[1] = 16;
	tabCopy2[2] = 32;
	tabCopy2[3] = 64;
	tabCopy2[4] = 0;

	std::cout << "tab :		";
	for (unsigned int i = 0; i < size; i++)
		std::cout << tab[i] << " ";
	std::cout << std::endl;

	std::cout << "tabCopy :	";
	for (unsigned int i = 0; i < size; i++)
		std::cout << tabCopy[i] << " ";
	std::cout << std::endl;

	std::cout << "tabCopy2 :	";
	for (unsigned int i = 0; i < size; i++)
		std::cout << tabCopy2[i] << " ";
	std::cout << std::endl;

	std::cout << BOLD << "-- Index out of bound --" << RESET << std::endl;
	try 
	{
		std::cout << tab[5] << std::endl;
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	// const Array<int> tabConst = tab;
	// for (unsigned int i = 0; i < size; i++)
	// {
	// 	// tabConst[i] = i;
	// 	std::cout << tabConst[i] << " ";
	// }
	const Array<int> tabConst[4];

	std::cout << tabConst[1] << std::endl;

	return 0;
}

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }