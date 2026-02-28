#pragma once
#include "Data.hpp"

typedef unsigned long int	uintptr_t;

class Serializer
{
    public:
        Serializer();
        ~Serializer();
        Serializer(const Serializer& other);
        Serializer& operator=(const Serializer& other);
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};