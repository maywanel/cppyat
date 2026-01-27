#include "PmergeMe.hpp"
#include <cstdlib>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
    if (this != &other) {
        _vector = other._vector;
        _deque = other._deque;
    }
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vector = other._vector;
        _deque = other._deque;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

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

void PmergeMe::run(int ac, char** av) {
    for (int i = 1; i < ac; i++) {
        std::string s = av[i];
        for (size_t j = 0; j < s.length(); j++) {
            if (!isdigit(s[j])) {
                std::cout << "Error" << std::endl;
                return;
            }
        }
        long val = std::atol(s.c_str());
        if (val < 0 || val > INT_MAX) {
            std::cout << "Error" << std::endl;
            return;
        }
        _vector.push_back(static_cast<int>(val));
        _deque.push_back(static_cast<int>(val));
    }
    std::cout << "Before: ";
    printContainer(_vector);
    struct timeval start, end;
    gettimeofday(&start, NULL);
    _vector = _mergeVector(_vector);
    gettimeofday(&end, NULL);
    double time_vec = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
    gettimeofday(&start, NULL);
    _deque = _mergeDeque(_deque);
    gettimeofday(&end, NULL);
    double time_deque = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
    std::cout << "After: ";
    printContainer(_vector);
    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << std::fixed << std::setprecision(5) << time_vec << " us" << std::endl;
    std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : " << std::fixed << std::setprecision(5) << time_deque << " us" << std::endl;
}

std::vector<int> PmergeMe::_mergeVector(std::vector<int>& arr) {
    if (arr.size() < 2) return arr;
    bool hasStraggler = false;
    int straggler = 0;
    if (arr.size() % 2 != 0) {
        hasStraggler = true;
        straggler = arr.back();
        arr.pop_back();
    }
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size(); i += 2) {
        if (arr[i] > arr[i+1])
            pairs.push_back(std::make_pair(arr[i], arr[i+1]));
        else
            pairs.push_back(std::make_pair(arr[i+1], arr[i]));
    }
    std::vector<int> largerElements;
    for (size_t i = 0; i < pairs.size(); ++i)
        largerElements.push_back(pairs[i].first);
    std::vector<int> sortedLarger = _mergeVector(largerElements);
    std::vector<int> mainChain;
    mainChain.reserve(arr.size() + (hasStraggler ? 1 : 0));
    mainChain = sortedLarger;
    std::vector<int> pending;
    std::vector<std::pair<int, int> > pairsCopy = pairs;
    for (size_t i = 0; i < sortedLarger.size(); ++i) {
        int largeVal = sortedLarger[i];
        for (size_t j = 0; j < pairsCopy.size(); ++j) {
            if (pairsCopy[j].first == largeVal) {
                 pending.push_back(pairsCopy[j].second);
                 pairsCopy.erase(pairsCopy.begin() + j);
                 break;
            }
        }
    }
    mainChain.insert(mainChain.begin(), pending[0]);
    int jacob[] = {0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845};
    size_t pendingSize = pending.size();
    size_t k = 2;
    while (1) {
        size_t endGroup = jacob[k];
        if (endGroup > pendingSize) endGroup = pendingSize;
        size_t startGroup = jacob[k-1];
        if (startGroup >= pendingSize) break;
        for (size_t i = endGroup; i > startGroup; --i) {
             int valToInsert = pending[i-1];
             int largerPair = sortedLarger[i-1];
             std::vector<int>::iterator bound = std::lower_bound(mainChain.begin(), mainChain.end(), largerPair);
             std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), bound, valToInsert);
             mainChain.insert(pos, valToInsert);
        }
        k++;
    }
    if (hasStraggler) {
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }
    return mainChain;
}

std::deque<int> PmergeMe::_mergeDeque(std::deque<int>& arr) {
    if (arr.size() < 2) return arr;
    bool hasStraggler = false;
    int straggler = 0;
    if (arr.size() % 2 != 0) {
        hasStraggler = true;
        straggler = arr.back();
        arr.pop_back();
    }
    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size(); i += 2) {
        if (arr[i] > arr[i+1])
            pairs.push_back(std::make_pair(arr[i], arr[i+1]));
        else
            pairs.push_back(std::make_pair(arr[i+1], arr[i]));
    }
    std::deque<int> largerElements;
    for (size_t i = 0; i < pairs.size(); ++i)
        largerElements.push_back(pairs[i].first);
    std::deque<int> sortedLarger = _mergeDeque(largerElements);
    std::deque<int> mainChain;
    mainChain = sortedLarger;
    std::deque<int> pending;
    std::deque<std::pair<int, int> > pairsCopy = pairs;
    for (size_t i = 0; i < sortedLarger.size(); ++i) {
        int largeVal = sortedLarger[i];
        for (size_t j = 0; j < pairsCopy.size(); ++j) {
            if (pairsCopy[j].first == largeVal) {
                 pending.push_back(pairsCopy[j].second);
                 pairsCopy.erase(pairsCopy.begin() + j);
                 break;
            }
        }
    }
    mainChain.push_front(pending[0]);
    int jacob[] = {0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845};
    size_t pendingSize = pending.size();
    size_t k = 2;
    while (1) {
        size_t endGroup = jacob[k];
        if (endGroup > pendingSize) endGroup = pendingSize;
        size_t startGroup = jacob[k-1];
        if (startGroup >= pendingSize) break;
        for (size_t i = endGroup; i > startGroup; --i) {
             int valToInsert = pending[i-1];
             int largerPair = sortedLarger[i-1];
             std::deque<int>::iterator bound = std::lower_bound(mainChain.begin(), mainChain.end(), largerPair);
             std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), bound, valToInsert);
             mainChain.insert(pos, valToInsert);
        }
        k++;
    }
    if (hasStraggler) {
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }
    return mainChain;
}
