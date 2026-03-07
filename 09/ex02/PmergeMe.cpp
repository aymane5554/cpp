#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    straggler = -1;
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
        this->straggler = other.straggler;
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

    if ((argc - 1) % 2 != 0)
    {
        tmp = strtol(argv[argc - 1], &end, 10);
        if (*end != '\0' || errno == ERANGE || tmp > 2147483647 || tmp < 0)
            throw std::runtime_error("Error");
        straggler = tmp;
        argc--;
    }
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

void PmergeMe::sort(int argc, char **argv)
{
    init_pairs(argc, argv);
    sort_winners(this->d);
    sort_winners(this->v);
    sort_losers(this->d);
    sort_losers(this->v);

    for (size_t i = 0; i < d.size(); i++)
    {
        std::cout << " " << d[i];
    }
    std::cout << std::endl;
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << " " << v[i];
    }
    std::cout << std::endl;
}

