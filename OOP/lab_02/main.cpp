#include <iostream>
#include "list.h"


template<typename T>
void print_list(List<T> & list)
{
	if (!list.empty())
		for (auto it = list.cbegin(); it != list.cend(); ++it)
			std::cout << *it << " ";

	std::cout << std::endl;
}



int main()
{
	int size = 5;

	List<int> l1;
    List<int> l2{ -5, -4, -3, -2, -1 };
    List<int> l3(l2);


	// constructor

	std::cout << "Constructors" << std::endl;
    std::cout << l1.size() << " " << l1.empty() << std::endl; // 0 1
    std::cout << l2.size() << " " << l2.empty() << std::endl; // 5 0
    std::cout << l3.size() << " " << l3.empty() << std::endl; // 5 0
	std::cout << std::endl;


	// push_back
    
	for (int i = 0; i < size; i++)
	{
		l1.push_back(i + 1);
		l2.push_back(i + 2);
		l3.push_back(i + 3);
	}

	std::cout << "push_back" << std::endl;
	print_list(l1); // 1 2 3 4 5
    print_list(l2); // -5 -4 -3 -2 -1 2 3 4 5 6
	print_list(l3); // -5 -4 -3 -2 -1 3 4 5 6 7
	std::cout << std::endl;

	// push_front
	
	l1.push_front(0);
	l2.push_front(0);
	l3.push_front(0);
    

	std::cout << "push_front" << std::endl;
	print_list(l1); // 0 1 2 3 4 5
    print_list(l2); // 0 -5 -4 -3 -2 -1 2 3 4 5 6
    print_list(l3); // 0 -5 -4 -3 -2 -1 3 4 5 6 7
	std::cout << std::endl;
	
	// insert
    
	l1.insert(3, 9);
	l2.insert(3, 9);
	l3.insert(3, 9);


	std::cout << "insert" << std::endl;
    print_list(l1); // 0 1 2 9 3 4 5
    print_list(l2); // 0 -5 -4 9 -3 -2 -1 2 3 4 5 6
    print_list(l3); // 0 -5 -4 9 -3 -2 -1 3 4 5 6 7
	std::cout << std::endl;

	// remove
	
	l1.remove(3);
	l2.remove(3);
	l3.remove(3);

	
	std::cout << "remove" << std::endl;
	print_list(l1); // 0 1 2 3 4 5
    print_list(l2); // 0 -5 -4 -3 -2 -1 2 3 4 5 6
	print_list(l3); // 0 -5 -4 -3 -2 -1 3 4 5 6 7
	std::cout << std::endl;

	// merge & equals
	
	List<int> lt{ 0, -5, -4, -3, -2, -1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5 };

	l2.merge(l1);


	std::cout << "merge & equals" << std::endl;
	std::cout << (l2 == lt) << std::endl; // 1
	std::cout << (l2 == l3) << std::endl; // 0
    print_list(l2); // 0 -5 -4 -3 -2 -1 2 3 4 5 6 0 1 2 3 4 5
	std::cout << std::endl;

	// --------------------------------
	
	//iterator

	std::cout << "iterator" << std::endl;

	auto it = l2.begin();

	std::cout << (*it) << std::endl; // 0
	++it;
	auto it1 = it;
	std::cout << (*it) << std::endl; // -5
	--it;
	auto it2 = it;
	std::cout << (*it) << std::endl; // 0

	std::cout << std::endl;

	std::cout << (it == it1) << std::endl; // 0
	std::cout << (it == it2) << std::endl; // 1

	std::cout << std::endl;

    print_list(l2); // 0 -5 -4 -3 -2 -1 2 3 4 5 6 0 1 2 3 4 5
    print_list(l3); // 0 -5 -4 -3 -2 -1 3 4 5 6 7
	std::cout << std::endl;

	return 0;
}

