#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cerrno>

enum e_type
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    INVALID
};

enum e_kewword
{
    NANF,
    INFF,
    NAN,
    INF,
    M_INFF,
    M_INF,
    NONE
};

e_kewword get_keyword(const char *literal)
{
    std::string str(literal);

    if (str == "nanf")
        return NANF;
    if (str == "+inff")
        return INFF;
    if (str == "nan") 
        return NAN;
    if (str == "+inf")
        return INF;
    if (str == "-inff")
        return M_INFF;
    if (str == "-inf")
        return M_INF;
    return NONE;
}

e_type getType(const char *literal)
{
    char *end = NULL;
    errno = 0;
    long int i = strtol(literal, &end, 10);
    if (*end == '\0' && errno != ERANGE && i >= std::numeric_limits<int>::min() && i <= std::numeric_limits<int>::max())
        return INT;
    errno = 0;
    double f = strtod(literal, &end);
    if (*end == '\0' && errno != ERANGE && f >= -std::numeric_limits<float>::max() && f <= std::numeric_limits<float>::max())
        return FLOAT;
    else if (end != literal && *end == 'f' && *(end + 1) == '\0' && errno != ERANGE && f >= -std::numeric_limits<float>::max() && f <= std::numeric_limits<float>::max())
        return FLOAT;
    errno = 0;
    strtod(literal, &end);
    if (*end == '\0' && errno != ERANGE)
        return DOUBLE;
    if (literal[1] == '\0' && std::isprint(literal[0]) && !std::isdigit(literal[0]))
        return CHAR;
    return INVALID;
}

void ScalarConverter::convert(const char *literal)
{
    e_kewword keyword = get_keyword(literal);
    if (keyword != NONE)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (keyword == NANF || keyword == INFF || keyword == M_INFF)
            std::cout << "float: " << literal << std::endl;
        else
            std::cout << "float: " << literal << "f" << std::endl;
        if (keyword == NAN || keyword == INF || keyword == M_INF)
            std::cout << "double: " << literal << std::endl;
        else
            std::cout << "double: " << literal << std::endl;
        return;
    }
    e_type type = getType(literal);
    switch (type)
    {
        case CHAR:
        {
            char c = literal[0];
            std::cout << "char: '" << c << "'" << std::endl;
            std::cout << "int: " << static_cast<int>(c) << std::endl;
            std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(c) << std::endl;
            break;
        }
        case INT:
        {
            int i = atoi(literal);
            if (i < 0 || i > 127)
                std::cout << "char: impossible" << std::endl;
            else if (!std::isprint(i))
                std::cout << "char: Non displayable" << std::endl;
            else
                std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
            std::cout << "int: " << i << std::endl;
            std::cout << "float: " << std::fixed << static_cast<float>(i) << "f" << std::endl;
            std::cout << "double: " << std::fixed << static_cast<double>(i) << std::endl;
            break;
        }
        case FLOAT:
        {
            float f = strtof(literal, NULL);
            if (f < 0 || f > 127 || f != f)
                std::cout << "char: impossible" << std::endl;
            else if (!std::isprint(static_cast<int>(f)))
                std::cout << "char: Non displayable" << std::endl;
            else
                std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
            if (f < static_cast<float>(std::numeric_limits<int>::min()) || f > static_cast<float>(std::numeric_limits<int>::max()) || f != f)
                std::cout << "int: impossible" << std::endl;
            else
                std::cout << "int: " << static_cast<int>(f) << std::endl;
            std::cout << "float: " << std::fixed << f << "f" << std::endl;
            std::cout << "double: " << std::fixed << static_cast<double>(f) << std::endl;
            break;
        }
        case DOUBLE:
        {
            double d = strtod(literal, NULL);
            if (d < 0 || d > 127 || d != d)
                std::cout << "char: impossible" << std::endl;
            else if (!std::isprint(static_cast<int>(d)))
                std::cout << "char: Non displayable" << std::endl;
            else
                std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
            if (d < static_cast<double>(std::numeric_limits<int>::min()) || d > static_cast<double>(std::numeric_limits<int>::max()) || d != d)
                std::cout << "int: impossible" << std::endl;
            else
                std::cout << "int: " << static_cast<int>(d) << std::endl;
            if (d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max() || d != d)
                std::cout << "float: impossible" << std::endl;
            else
                std::cout << "float: " << std::fixed << static_cast<float>(d) << "f" << std::endl;
            std::cout << "double: " << std::fixed << d << std::endl;
            break;
        }
        default:
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            break;
    }
}
