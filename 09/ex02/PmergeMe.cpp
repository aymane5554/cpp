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
        this->nums = other.nums;
        this->straggler = other.straggler;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
}

bool isduplicate(const std::vector<int>& nums, int num)
{
    return std::find(nums.begin(), nums.end(), num) != nums.end();
}

void PmergeMe::parse_input(int argc, char **argv)
{
    char *end;
    long long tmp;

    for (int i = 1; i < argc; i++)
    {
        errno = 0;
        tmp = strtol(argv[i], &end, 10);
        if (*end != '\0' || errno == ERANGE || tmp > 2147483647 || tmp < 0 || isduplicate(nums, tmp))
            throw std::runtime_error("Error");
        nums.push_back(tmp);
    }
    this->straggler = -1;
}
