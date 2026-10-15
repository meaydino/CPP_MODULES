#include "BitcoinExchange.hpp"
#include <sstream>
#include <iostream>
#include <cstdlib>


BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other): _database(other._database)
{}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if(this != &other)
    {
        this->_database = other._database;
    }
    return(*this);
}

BitcoinExchange::~BitcoinExchange(){}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if(!file)
    {
        std::cout << "Error: could not open database." << std::endl;
        return;
    }
    std::string line;

    std::getline(file, line);

    while(std::getline(file, line))
    {
        size_t comma = line.find(',');

        if(comma == std::string::npos)
            continue;

        std::string date = line.substr(0, comma);
        std::string rate = line.substr(comma + 1);

        double value = std::atof(rate.c_str());
        _database[date] = value;
    }
}

void BitcoinExchange::processInput(const std::string& filename)
{
    std::ifstream file(filename.c_str());

    if (!file)
    {
        std::cout << "Error: could not open file." << std::endl;
        return;
    }
    std::string line;
    std::getline(file, line);

    while(std::getline(file, line))
    {
        if(line.empty())
            continue;
        size_t pipe = line.find('|');

        if(pipe == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = line.substr(0, pipe);
        std::string valueStr = line.substr(pipe + 1);

        date.erase(date.find_last_not_of(" ") + 1);
        valueStr.erase(0, valueStr.find_first_not_of(" "));
        if(!isValidDate(date))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        if(!isValidValue(valueStr))
            continue;

        double value = std::atof(valueStr.c_str());
        double rate = getRate(date);
        printValue(value, rate, date);

    }
}

bool BitcoinExchange::isValidValue(const std::string& value)
{
    if (value.empty())
        return false;

    std::stringstream ss(value);
    double number;
    ss >> number;
    if (ss.fail())
        return false;
    char c;

    if (ss >> c)
        return false;
    if (number < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    if (number > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

double BitcoinExchange::getRate(const std::string &date)
{
    std::map<std::string, double>::iterator it;

    it = _database.lower_bound(date);

    if(it == _database.end())
    {
        --it;
        return(it->second);
    }
    if(it->first == date)
    {
        return(it->second);
    }
    if(it == _database.begin())
        return(it->second);
    --it;
    return(it->second);
}

void BitcoinExchange::printValue(const double &value, const double &rate, const std::string &date)
{
    std::cout << date << " => " << value << " = " << value * rate << std::endl;
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
    size_t first = date.find('-');
    size_t second = date.find('-', first + 1);

    if (first == std::string::npos || second == std::string::npos)
        return false;


    std::string year = date.substr(0, first);
    std::string month = date.substr(first + 1, second - first - 1);
    std::string day = date.substr(second + 1);


    int y = std::atoi(year.c_str());
    int m = std::atoi(month.c_str());
    int d = std::atoi(day.c_str());


    if (y < 0)
        return false;

    if (m < 1 || m > 12)
        return false;

    int maxDay;
    if (m == 2)
    {
        if (isLeapYear(y))
            maxDay = 29;
        else
            maxDay = 28;
    }
    else if (m == 4 || m == 6 || m == 9 || m == 11)
    {
        maxDay = 30;
    }
    else
    {
        maxDay = 31;
    }
    if (d < 1 || d > maxDay)
        return false;


    return true;
}
bool BitcoinExchange::isLeapYear(int year)
{
    if (year % 400 == 0)
        return true;

    if (year % 100 == 0)
        return false;

    if (year % 4 == 0)
        return true;

    return false;
}
