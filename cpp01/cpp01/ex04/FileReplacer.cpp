#include "FileReplacer.hpp"
#include <iostream>
#include <fstream>

FileReplacer::FileReplacer(std::string filename, std::string s1, std::string s2)
    :_filename(filename), _s1(s1), _s2(s2)
{
}

FileReplacer::~FileReplacer()
{
}

bool FileReplacer::replaceInFile()
{
    std::string content = _readFile();
    if(content.empty())
        return false;
    std::string result = _replaceString(content);
    return _writeFile(result);
}
std::string FileReplacer::_readFile()
{
    std::ifstream inputFile(_filename.c_str());
    if(!inputFile.is_open())
    {
        std::cout << "Error: cannot be open file" << _filename << std::endl;
        return("");
    }
    std::string content, line;
    while(std::getline(inputFile, line))
    {
        content += line;
        if(!inputFile.eof())
            content += "\n";
    }
    inputFile.close();
    return(content);
}

bool FileReplacer::_writeFile(const std::string &content)
{
    std::string outputFilename = _filename + ".replace";
    std::ofstream outputFile(outputFilename.c_str());
    if(!outputFile.is_open())
    {
        std::cout << "Error: cannot create output file" << outputFilename <<  std::endl;
        return(false);
    }
    outputFile << content;
    outputFile.close();
    return(true);
}

std::string FileReplacer::_replaceString(const std::string &content)
{
    std::string result = "";
    for(size_t i = 0; i < content.size(); i++)
    {
        if(content.substr(i, _s1.size()) == _s1)
        {
            result += _s2;
            i += _s1.size() -1;
        }
        else
            result += content[i];
    }
    return(result);
}
