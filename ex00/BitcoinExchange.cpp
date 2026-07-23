#include "BitcoinExchange.hpp"

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

        double value = std::stof(rate.c_str());
        _database[rate] = value;
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
        size_t pipe = line.find('|');

        if(pipe == std::string::npos)
        {
            std::cout << "Error: bad input =>" << line << std::endl;
            continue;
        }
        std::string date = line.substr(0, pipe);
        std::string valueStr = line.substr(pipe + 1);

        date.erase(date.find_last_not_of(" ") + 1);
        valueStr.erase(0, valueStr.find_first_not_of(" "));
    }
}
