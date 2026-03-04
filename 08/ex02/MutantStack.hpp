#pragma once

#include <stack>

template <typename T, class Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
    public:
        typedef typename Container::iterator iterator;
        typedef typename Container::const_iterator const_iterator;
        const_iterator begin() const
        {
            return this->c.begin();
        }
        const_iterator end() const
        {
            return this->c.end();
        }
        iterator begin()
        {
            return this->c.begin();
        }
        iterator end()
        {
            return this->c.end();
        }
        MutantStack() {}
        MutantStack(const MutantStack& other): std::stack<T, Container>(other) {}
        MutantStack& operator=(const MutantStack& other)
        {
            std::stack<T, Container>::operator=(other);
            return *this;
        }
        ~MutantStack() {}
};
