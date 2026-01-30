#pragma once

#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <climits>
#include <sys/time.h>

class PmergeMe {
    private:
        std::vector<int> _vector;
        std::deque<int> _deque;

        std::vector<int> _mergeVector(std::vector<int>& arr);
        std::deque<int> _mergeDeque(std::deque<int>& arr);
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void run(int ac, char** av);
        template <typename T>
        void printContainer(const T& container) {
            typename T::const_iterator it;
            int i = 0;
            for (it = container.begin(); it != container.end(); ++it) {
                if (i++ >= 5 && container.size() > 10) { 
                    std::cout << "[...]";
                    break;
                }
                std::cout << *it << " ";
            }
            std::cout << std::endl;
        }
};
