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

void PmergeMe::make_pairs(std::vector <int> &winners, std::vector <int> &losers, std::vector <int> &nums, int &_straggler)
{
    for (size_t i = 0; i < nums.size(); i += 2)
    {
        if (i + 1 < nums.size())
        {
            if (nums[i] < nums[i + 1])
            {
                winners.push_back(nums[i + 1]);
                losers.push_back(nums[i]);
            }
            else
            {
                winners.push_back(nums[i]);
                losers.push_back(nums[i + 1]);
            }
        }
        else
        {
            _straggler = nums[i];
        }
    }
}

void PmergeMe::parse_input(int argc, char **argv, std::vector <int> &nums)
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
}

void PmergeMe::sort_vec(std::vector <int> nums)
{
    if (nums.size() == 2)
    {
        if (nums[0] > nums[1])
        {
            v.push_back(nums[1]);
            v.push_back(nums[0]);
        }
        else
        {
            v.push_back(nums[0]);
            v.push_back(nums[1]);
        }
        return ;
    }
    std::vector <int> winners;
    std::vector <int> losers;
    int stragler = -1;
    make_pairs(winners, losers, nums, stragler);
    sort_vec(winners);
    merge_losers_vec(losers, stragler);
}

void PmergeMe::sort_deque(std::vector <int> nums)
{
    if (nums.size() == 2)
    {
        if (nums[0] > nums[1])
        {
            d.push_back(nums[1]);
            d.push_back(nums[0]);
        }
        else
        {
            d.push_back(nums[0]);
            d.push_back(nums[1]);
        }
        return ;
    }
    std::vector <int> winners;
    std::vector <int> losers;
    int stragler = -1;
    make_pairs(winners, losers, nums, stragler);
    sort_deque(winners);
    merge_losers_deque(losers, stragler);
}

std::vector<int> PmergeMe::jacobsthal_seq(size_t size)
{
    std::vector<int> jacob;

    jacob.push_back(0);
    if (!size)
    {
        return jacob;
    }
    jacob.push_back(1);
    if (size == 1)
    {
        return jacob;
    }
    jacob.push_back(0);
    jacob.push_back(1);
    for (int i = 2; i <= size; i++)
    {
        jacob.push_back(jacob[i - 1] + 2 * jacob[i - 2]);
    }
    return (jacob);     
}

void PmergeMe::merge_losers_vec(std::vector <int> &losers, int stragler)
{
    std::vector <int>jacob = jacobsthal_seq(losers.size());
}

void PmergeMe::merge_losers_deque(std::vector <int> &losers, int stragler)
{
    std::vector <int>jacob = jacobsthal_seq(losers.size());
}

void PmergeMe::sort(int argc, char **argv)
{
    std::vector <int> nums;

    parse_input(argc, argv, nums);
    sort_vec(nums);
    sort_deque(nums);
}
