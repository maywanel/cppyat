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
};
