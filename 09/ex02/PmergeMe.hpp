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

        void                parse_input(int argc, char **argv, std::vector <int> &nums);
        void                make_pairs(std::vector <int> &winners, std::vector <int> &losers, std::vector <int> &nums, int &_stragler);
        void                sort_vec(std::vector <int> nums);
        void                sort_deque(std::vector <int> nums);
        void                merge_losers_vec(std::vector <int> &losers, int stragler);
        void                merge_losers_deque(std::vector <int> &losers, int stragler);
        std::vector<int>    jacobsthal_seq(size_t size);
    public:
        void sort(int argc, char **argv);
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();
};
