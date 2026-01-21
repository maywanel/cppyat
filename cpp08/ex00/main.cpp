#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main() {
    std::cout << "--- Vector Test ---" << std::endl;
    std::vector<int> vec;
    for (int i = 0; i < 5; ++i) vec.push_back(i);
    try {
        std::cout << "Finding 3 in vector: " << *easyfind(vec, 3) << std::endl;
        std::cout << "Finding 10 in vector: ";
        std::cout << *easyfind(vec, 10) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\n--- List Test ---" << std::endl;
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    try {
        std::cout << "Finding 20 in list: " << *easyfind(lst, 20) << std::endl;
        std::cout << "Finding 5 in list: ";
        std::cout << *easyfind(lst, 5) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
