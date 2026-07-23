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
};

#endif