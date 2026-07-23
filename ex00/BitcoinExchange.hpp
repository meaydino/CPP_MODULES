#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>

class BitcoinExchange
{
    private:
        std::map<std::string, double> _database;

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        void loadDatabase(const std::string& filename);
        void processInput(const std::string& filename);
        bool isValidValue(const std::string &value);
        double getRate(const std::string &date);
        void printValue(const double &value, const double &rate, const std::string &date);
        bool isValidDate(const std::string& date);
        bool isLeapYear(int year);
};

#endif