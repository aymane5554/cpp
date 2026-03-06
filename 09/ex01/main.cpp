#include "RPN.hpp"  

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <RPN expression>" << std::endl;
        return 1;
    }
    RPN rpn;
    try
    {
        int result = rpn.calculate(argv[1]);
        std::cout << "Result: " << result << std::endl;
    }
    catch (const std::runtime_error& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}