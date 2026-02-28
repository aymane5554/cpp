#pragma once

class Data
{
    public:
        int a,b,c;
        Data();
        Data(int a, int b, int c);
        ~Data();
        Data(const Data& other);
        Data& operator=(const Data& other);
};
