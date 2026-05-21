#pragma once

#include <iostream>
#include <stack>
#include <cstdlib>
#include <sstream>
#include <stdexcept>
#include <string> 
#include <list>

class RPN 
{
    public:
        RPN();
        ~RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        int calculate(const std::string& expression);
    private:
        bool isoperator(char c);
        int applyOperator(int a, int b, char op);
        std::stack<int, std::list<int> > _stack;
};
