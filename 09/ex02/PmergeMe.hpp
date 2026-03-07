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
        std::deque <int> d;
        std::vector <int> v;
        std::vector<int> wins;
        std::vector<int> loss;
        void sort_winners_deque();
        void sort_winners_vec();
    public:
        PmergeMe();
        void init_pairs(int argc, char **argv);
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();
};
