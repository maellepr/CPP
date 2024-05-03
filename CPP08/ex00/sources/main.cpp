#include "../include/easyfind.hpp"

int main(void)
{
	std::cout << BOLD << "-- Test with a vector --" << RESET << std::endl;
	std::vector<int> tab(5, 4);
	try
	{
		std::cout << easyfind(tab, 4) << " was find in the vector !" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << easyfind(tab, 11) << " was find in the vector !" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}	
	std::cout << BOLD << "-- Test with a list --" << RESET << std::endl;	
	std::list<int> list(5);
	list.push_front(4);
	list.push_front(5);
	list.push_front(6);
	list.push_front(7);
	list.push_front(8);
	try
	{
		std::cout << easyfind(list, 3) << " was find in the list !" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << easyfind(list, 7) << " was find in the list !" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}