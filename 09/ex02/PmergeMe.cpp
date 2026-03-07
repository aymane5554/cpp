#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        this->d = other.d;
        this->v = other.v;
        this->wins = other.wins;
        this->loss = other.loss;
        
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::init_pairs(int argc, char **argv)
{
    char *end;
    long long tmp;
    int a, b;

    for (int i = 1; i < argc; i++)
    {
        errno = 0;
        tmp = strtol(argv[i], &end, 10);
        if (*end != '\0' || errno == ERANGE || tmp > 2147483647 || tmp < 0)
            throw std::runtime_error("Error");
        if (i % 2 != 0)
            a = tmp;
        else
        {
            b = tmp;
            if (a < b)
            {
                loss.push_back(a);
                wins.push_back(b);
            }
            else
            {
                loss.push_back(b);
                wins.push_back(a);
            }
        }
    }
}

void PmergeMe::sort_winners_deque()
{
    for (size_t i = 0; i < wins.size(); i++)
    {
        d.push_back(wins[i]);
    }
    std::sort(d.begin(), d.end());
}

void PmergeMe::sort_winners_vec()
{
    for (size_t i = 0; i < wins.size(); i++)
    {
        v.push_back(wins[i]);
    }
    std::sort(v.begin(), v.end());
}
