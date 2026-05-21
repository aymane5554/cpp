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
            throw std::runtime_error(argv[i]);
        nums.push_back(tmp);
    }
}

std::vector<int> insertion_order(const std::vector<int> &jacob)
{
    std::vector<int> order;

    for (size_t i = 2; i < jacob.size(); i++)
    {
        order.push_back(jacob[i]);
        for (int k = jacob[i] - 1; k > jacob[i-1]; k--)
            order.push_back(k);
    }
    return order;
}

std::vector<int> PmergeMe::jacobsthal_seq(size_t size)
{
    std::vector<int> jacob;

    jacob.push_back(0);
    if (size == 0)
        return jacob;
    jacob.push_back(1);
    if (size == 1)
        return jacob;
    while (jacob.back() < (int)size)
    {
        int num = jacob.back() + 2 * jacob[jacob.size()-2];
        jacob.push_back(num);
    }
    return (jacob);
}

void PmergeMe::sort_deque(std::vector<int> nums)
{
    if (nums.size() == 1)
    {
        d.push_back(nums[0]);
        return;
    }
    std::vector<int> winners;
    std::vector<int> losers;
    int stragler = -1;
    make_pairs(winners, losers, nums, stragler);
    sort_deque(winners);

    std::vector<int> winners_aligned;
    std::vector<int> losers_aligned;
    for (size_t i = 0; i < d.size(); i++)
    {
        std::vector<int>::iterator winner_iterator = std::find(winners.begin(), winners.end(), d[i]);
        size_t index = winner_iterator - winners.begin();
        losers_aligned.push_back(losers[index]);
        winners_aligned.push_back(winners[index]);
    }
    d.insert(d.begin(), losers_aligned[0]);
    merge_losers_deque(losers_aligned, winners_aligned, stragler);
}

void PmergeMe::sort_vec(std::vector<int> nums)
{
    if (nums.size() == 1)
    {
        v.push_back(nums[0]);
        return;
    }
    std::vector<int> winners;
    std::vector<int> losers;
    int stragler = -1;
    make_pairs(winners, losers, nums, stragler);
    sort_vec(winners);

    std::vector<int> winners_aligned;
    std::vector<int> losers_aligned;
    for (size_t i = 0; i < v.size(); i++)
    {
        std::vector<int>::iterator winner_iterator = std::find(winners.begin(), winners.end(), v[i]);
        size_t index = winner_iterator - winners.begin();
        losers_aligned.push_back(losers[index]);
        winners_aligned.push_back(winners[index]);
    }
    v.insert(v.begin(), losers_aligned[0]);
    merge_losers_vec(losers_aligned, winners_aligned, stragler);
}

void PmergeMe::merge_losers_vec(std::vector<int> &losers, std::vector<int> &winners, int stragler)
{
    std::vector<int> jacob = jacobsthal_seq(losers.size());
    std::vector<int> order = insertion_order(jacob);

    size_t i = 0;
    while (i < order.size())
    {
        int idx = order[i];
        if ((size_t)idx >= losers.size() || idx <= 0)
        {
            i++;
            continue;
        }
        int win = winners[idx];
        int los = losers[idx];
        std::vector<int>::iterator it = std::lower_bound(v.begin(), v.end(), win);
        std::vector<int>::iterator in = std::lower_bound(v.begin(), it, los);
        v.insert(in, los);
        i++;
    }
    if (stragler != -1)
    {
        std::vector<int>::iterator in = std::lower_bound(v.begin(), v.end(), stragler);
        v.insert(in, stragler);
    }
}

void PmergeMe::merge_losers_deque(std::vector<int> &losers, std::vector<int> &winners, int stragler)
{
    std::vector<int> jacob = jacobsthal_seq(losers.size());
    std::vector<int> order = insertion_order(jacob);

    size_t i = 0;
    while (i < order.size())
    {
        int idx = order[i];
        if (idx <= 0 || (size_t)idx >= losers.size())
        {
            i++;
            continue;
        }
        int win = winners[idx];
        int los = losers[idx];
        std::deque<int>::iterator it = std::lower_bound(d.begin(), d.end(), win);
        std::deque<int>::iterator in = std::lower_bound(d.begin(), it, los);
        d.insert(in, los);
        i++;
    }
    if (stragler != -1)
    {
        std::deque<int>::iterator in = std::lower_bound(d.begin(), d.end(), stragler);
        d.insert(in, stragler);
    }
}

void PmergeMe::sort(int argc, char **argv)
{
    std::vector <int> nums;
    std::vector <int> nums2;

    clock_t start = clock();
    parse_input(argc, argv, nums);
    sort_vec(nums);
    clock_t end = clock();
    
    clock_t start2 = clock();
    parse_input(argc, argv, nums2);
    sort_deque(nums2);
    clock_t end2 = clock();

    std::cout << "Before: ";
    for (size_t i = 0; i < nums.size(); i++)
    {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "After: ";
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    double time_vec = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
    double time_deque = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC * 1000;
    std::cout << "Time taken by std::vector: " << time_vec << " ms" << std::endl;
    std::cout << "Time taken by std::deque: " << time_deque << " ms" << std::endl;
}
