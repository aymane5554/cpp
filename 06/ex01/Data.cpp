#include "Data.hpp"

Data::Data() : a(0), b(0), c(0) {}

Data::Data(int a, int b, int c) : a(a), b(b), c(c) {}

Data::~Data() {}

Data::Data(const Data& other) : a(other.a), b(other.b), c(other.c) {}

Data& Data::operator=(const Data& other)
{
    a = other.a;
    b = other.b;
    c = other.c;
    return *this;
}
