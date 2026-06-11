#include "BitcoinExchange.hpp"

void BitcoinExchange::exec(const std::pair<std::string, double> &in)
{

    std::map <std::string, double>::iterator it = db.lower_bound(in.first);
    if (it->first != in.first)
        it--;
    std::cout << in.first << "=> " << in.second << " = " << it->second * in.second << std::endl;
}

BitcoinExchange::BitcoinExchange (char *input)
{
    db_file = NULL;
    in_file = NULL;
    try 
    {
        db_file = new std::ifstream;
        in_file = new std::ifstream;
        db_file->open("data.csv");
        if (db_file->fail())
            throw std::runtime_error("Error Opening DataBase");
        in_file->open(input);
        if (in_file->fail())
            throw std::runtime_error("Error Opening Input File");
    }
    catch (std::exception &e)
    {
        if (db_file)
            delete db_file;
        if (in_file)
            delete in_file;
        throw ;
    }
    try
    {
        read_db();
        read_input();
    }
    catch(const std::exception& e)
    {
        delete db_file;
        delete in_file;
        throw ;
    }
}

BitcoinExchange::BitcoinExchange ()
{
    db_file = NULL;
    in_file = NULL;
    try 
    {
        db_file = new std::ifstream;
        in_file = new std::ifstream;
        db_file->open("data.csv");
        if (db_file->fail())
            throw std::runtime_error("Error Opening DataBase");
        in_file->open("input.txt");
        if (in_file->fail())
            throw std::runtime_error("Error Opening Input File");
    }
    catch (std::exception &e)
    {
        if (db_file)
            delete db_file;
        if (in_file)
            delete in_file;
        throw ;
    }
    try
    {
        read_db();
        read_input();
    }
    catch(const std::exception& e)
    {
        delete db_file;
        delete in_file;
        throw ;
    }
}

BitcoinExchange::~BitcoinExchange()
{
    delete db_file;
    delete in_file;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
    db_file = obj.db_file;
    in_file = obj.in_file;
    db = obj.db;
    try
    {
        read_db();
        read_input();
    }
    catch(const std::exception& e)
    {
        delete db_file;
        delete in_file;
        throw ;
    }
}

BitcoinExchange &BitcoinExchange::operator =(const BitcoinExchange &obj)
{
    if (this != &obj)
    {
        delete db_file;
        delete in_file;
        db_file = obj.db_file;
        in_file = obj.in_file;
        db = obj.db;
    }
    return *this;
}
void BitcoinExchange::read_db()
{
    std::string line;
    std::string date;
    size_t pos;
    char *end;
    double   price;

    std::getline(*db_file, line);
    while (std::getline(*db_file, line))
    {
        pos = line.find(',');
        if (pos != std::string::npos)
        {
            date = line.substr(0, pos);
            end = NULL;
            errno = 0;
            price = std::strtod(line.substr(pos + 1).c_str(), &end);
            if (*end != '\0' || errno == ERANGE)
                throw std::runtime_error("error -> " + line);
            db.insert(std::make_pair(date, price));
        }
    }
}

void strim(std::string &str)
{
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");
    if (start == std::string::npos || end == std::string::npos)
        str = "";
    else
        str = str.substr(start, end - start + 1);
}

void parse_date(std::string &date)
{
    int year, mon, day;
    std::string ystr, mstr, dstr;
    size_t pos1, pos2;
    char *end = NULL;

    pos1 = date.find('-');
    if (pos1 == std::string::npos)
        throw std::runtime_error("error -> " + date);
    pos2 = date.find('-', pos1 + 1);
    if (pos2 == std::string::npos)
        throw std::runtime_error("error -> " + date);
    
    if (pos1 == date.size() -1 || pos2 == date.size() - 1)
        throw std::runtime_error("error -> " + date);
    ystr = date.substr(0, pos1);
    mstr = date.substr(pos1 + 1, pos2 - pos1 - 1);
    dstr = date.substr(pos2 + 1);
    if (ystr.size() != 4 || mstr.size() != 2 || dstr.size() != 2)
        throw std::runtime_error("error -> " + date);
    year = strtol(ystr.c_str(), &end, 10);
    if (*end != '\0' || errno == ERANGE || year < 2009 || year > 2022)
        throw std::runtime_error("error -> " + date);
    end = NULL;
    mon = strtol(mstr.c_str(), &end, 10);
    if (*end != '\0' || errno == ERANGE || mon < 1 || mon > 12)
        throw std::runtime_error("error -> " + date);
    end = NULL;
    day = strtol(dstr.c_str(), &end, 10);
    if (*end != '\0' || errno == ERANGE || day < 0 || day > 31)
    {
        throw std::runtime_error("error -> " + date);
    }
    if (mon == 2 && day > 28)
    {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            return ;
        throw std::runtime_error("error -> " + date);
    }
    if (mon < 8)
    {
        if (mon % 2 == 0 && day == 31)
        {
            throw std::runtime_error("error -> " + date);
        }
        return ;
    }
    if (mon >= 8)
    {
        if (mon % 2 != 0 && day == 31)
        {
            throw std::runtime_error("error -> " + date);
        }
        return ;
    }
    
}

void BitcoinExchange::read_input()
{
    std::string line;
    std::string date;
    std::string num;
    size_t pos;
    char *end;
    double   price;

    std::getline(*in_file, line);
    strim(line);
    if (line != "date | value")
        throw std::runtime_error("error no header");
    while (std::getline(*in_file, line))
    {
        try
        {
            pos = line.find('|');
            if (pos == line.size() - 1)
                throw std::runtime_error("error -> " + line);
            if (pos != std::string::npos)
            {
                date = line.substr(0, pos - 1);
                parse_date(date);
                end = NULL;
                errno = 0;
                num = line.substr(pos + 1);
                if (num.length() <= 1 || num[0] != ' ' || !std::isdigit(num[1]))
                    throw std::runtime_error("error -> " + line);
                price = strtod(num.c_str(), &end);
                if (*end != '\0' || errno == ERANGE || price < 0 || price > 1000.0)
                    throw std::runtime_error("error -> " + line);
                exec(std::make_pair(date, price));
            }
            else
                throw std::runtime_error("error -> " + line);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}
