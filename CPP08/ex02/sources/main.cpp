#include "../include/MutantStack.hpp"

int main(void)
{
	std::cout << BOLD << "-- Test with a MutantStack instance --" << RESET << std::endl;
	MutantStack<int>	mstack;
	mstack.push(10);
	mstack.push(11);
	mstack.push(12);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	while (it != ite)
		std::cout << *it++ << " ";
	std::cout << std::endl;

	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();

	while (rit != rite)
		std::cout << *rit++ << " ";
	std::cout << std::endl; 

	std::cout << BOLD << "-- Test with a vector --" << RESET << std::endl;
	std::vector<int>	vector;
	vector.push_back(10);
	vector.push_back(11);
	vector.push_back(12);

	std::vector<int>::iterator it_vec = vector.begin();
	std::vector<int>::iterator ite_vec = vector.end();

	while (it_vec != ite_vec)
		std::cout << *it_vec++ << " ";
	std::cout << std::endl;


	std::cout << BOLD << "-- Test with a list --" << RESET << std::endl;
	std::list<int>		list;
	list.push_back(10);
	list.push_back(11);
	list.push_back(12);

	std::list<int>::iterator it_list = list.begin();
	std::list<int>::iterator ite_list = list.end();

	while (it_list != ite_list)
		std::cout << *it_list++ << " ";
	std::cout << std::endl;

	// MutantStack<int> mstack;
	// mstack.push(5);
	// mstack.push(17);
	// std::cout << mstack.top() << std::endl;
	// mstack.pop();
	// std::cout << mstack.size() << std::endl;
	// mstack.push(3);
	// mstack.push(5);
	// mstack.push(737);
	// //[...]
	// mstack.push(0);
	// MutantStack<int>::iterator it = mstack.begin();
	// MutantStack<int>::iterator ite = mstack.end();
	// ++it;
	// --it;
	// while (it != ite)
	// {
	// std::cout << *it << std::endl;
	// ++it;
	// }
	// std::stack<int> s(mstack);

	// std::list<int> mstack;
	// mstack.push_back(5);
	// mstack.push_back(17);
	// std::cout << mstack.back() << std::endl;
	// mstack.pop_back();
	// std::cout << mstack.size() << std::endl;
	// mstack.push_back(3);
	// mstack.push_back(5);
	// mstack.push_back(737);
	// //[...]
	// mstack.push_back(0);
	// std::list<int>::iterator it = mstack.begin();
	// std::list<int>::iterator ite = mstack.end();
	// ++it;
	// --it;
	// while (it != ite)
	// {
	// std::cout << *it << std::endl;
	// ++it;
	// }
	// std::list<int> s(mstack);

	return 0;
}