# pragma once

#include <map>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <exception>
#include <cerrno>

class BitcoinExchange
{
    std::map <std::string, double> db;
    std::map <std::string, double> input;
    std::ifstream *db_file;
    std::ifstream *in_file;

    public:
        BitcoinExchange (char *input);
        BitcoinExchange ();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &obj);
        BitcoinExchange &operator =(const BitcoinExchange &obj);
        void read_db();
        void read_input();
};
