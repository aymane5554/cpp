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
        int straggler;
    
        void init_pairs(int argc, char **argv);
    
        template <typename T>
        void sort_winners(T &container)
        {
            for (size_t i = 0; i < wins.size(); i++)
            {
                container.push_back(wins[i]);
            }
            std::sort(container.begin(), container.end());
        }
    
        template <typename T>
        void sort_losers(T &container)
        {
        }
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        void sort(int argc, char **argv);
        ~PmergeMe();
};
