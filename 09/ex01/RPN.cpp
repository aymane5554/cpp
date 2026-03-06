#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& other)
{
    *this = other;
}

RPN& RPN::operator=(const RPN& other)

{
    _stack = other._stack;
    return *this;
}

int RPN::calculate(const std::string& expression)
{
    int a,b;

    for (int i = 0; expression[i]; i++)
    {
        int c = expression[i];
        if (std::isdigit(c))
        {
            if (expression[i + 1] != '\0' && expression[i + 1] != ' ')
                throw std::runtime_error("Invalid format");
            _stack.push(expression[i] - '0');
        }
        else if (isoperator(expression[i]))
        {
            if (expression[i + 1] != '\0' && expression[i + 1] != ' ')
                throw std::runtime_error("Invalid format");
            if (_stack.size() < 2)
                throw std::runtime_error("Invalid format");
            b = _stack.top();
            _stack.pop();
            a = _stack.top();
            _stack.pop();
            _stack.push(applyOperator(a, b, expression[i]));
        }
    }
    if (_stack.size() != 1)
        throw std::runtime_error("too many operands");

    return _stack.top();
}

bool RPN::isoperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::applyOperator(int a, int b, char op)
{
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) {
                throw std::runtime_error("Division by zero");
            }
            return a / b;
    }
    return 0;
}
