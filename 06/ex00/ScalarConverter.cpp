#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>

enum e_type
{
    TYPE_CHAR,
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_INVALID
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
    if (str == "inf")
        return INFF;
    if (str == "nan") 
        return NAN;
    if (str == "inf")
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
    long int i = strtol(literal, &end, 10);
    if (*end == '\0')
        return TYPE_INT;
    float f = strtof(literal, &end);
    if (*end == '\0')
        return TYPE_FLOAT;
    double d = strtod(literal, &end);
    if (*end == '\0')
        return TYPE_DOUBLE;
    return TYPE_INVALID;
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
}
