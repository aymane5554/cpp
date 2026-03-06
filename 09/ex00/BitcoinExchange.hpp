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
    std::ifstream *db_file;
    std::ifstream *in_file;
    void read_db();
    void read_input();
    void exec(const std::pair<std::string, double> &in);

    public:
        BitcoinExchange (char *input);
        BitcoinExchange ();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &obj);
        BitcoinExchange &operator =(const BitcoinExchange &obj);
};
