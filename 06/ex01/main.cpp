#include "Serializer.hpp"
#include <iostream>

uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}


int main()
{
    Data d(1, 2, 3);

    uintptr_t uinteger = Serializer::serialize(&d);
    std::cout << "Serialized data: " << uinteger << std::endl;

    Data* deserializedData = Serializer::deserialize(uinteger);
    std::cout << "Deserialized data: a = " << deserializedData->a << ", b = " << deserializedData->b << ", c = " << deserializedData->c << std::endl;

    return 0;
}
