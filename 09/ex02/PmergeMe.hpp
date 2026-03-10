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
        int         straggler;

        void                parse_input(int argc, char **argv, std::vector <int> &nums);
        void                make_pairs(std::vector <int> winners, std::vector <int> losers, std::vector <int> nums);
        void                sort_vec(std::vector <int> nums);
        void                sort_deque(std::vector <int> nums);
        void                merge_losers_vec(std::vector <int> losers);
        void                merge_losers_deque(std::vector <int> losers);
        void                sort(int argc, char **argv);
        std::vector<int>    jacobsthal_seq();
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();
};
