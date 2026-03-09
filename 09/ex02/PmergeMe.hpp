#pragma once
#include <iostream>
#include <cstdlib>
#include <deque>
#include <vector>
#include <cerrno>
#include <exception>
#include <stdexcept>
#include <algorithm>

class PmergeMe
{
    private:
        std::deque  <int> d;
        std::vector <int> v;
        std::vector <int> nums;
        int         straggler;
        void        parse_input(int argc, char **argv);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();
};
