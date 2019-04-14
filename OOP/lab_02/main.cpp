#include <iostream>
#include "list.h"

using namespace std;

int main()
{
    int size = 5;

    List<int> l0 {0, 1, 2, 3, 4};
    List<int> l1(size);


    for (int i = 0; i < 5; i++)
        l1.push_back(i);


    for (int i = 0; i < l0.size(); i++)
        std::cout << l0[i] << " ";
    std::cout << std::endl;


    for (int i = 0; i < l1.size(); i++)
        std::cout << l1[i] << " ";
    std::cout << std::endl;

    std::cout << (l0 == l1) << std::endl;

    List<int> l2(l0);

    for (int i = 0; i < l2.size(); i++)
        std::cout << l2[i] << " ";
    std::cout << std::endl;

    return 0;
}
