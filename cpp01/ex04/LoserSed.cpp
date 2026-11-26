#include "LoserSed.hpp"
#include <string>

LoserSed::LoserSed(const std::string& filename, const std::string& oldStr, const std::string& newStr) : _filename(filename), _oldString(oldStr), _newString(newStr)
{
    this->_oldStringSize = oldStr.length();
    this->_newStringSize = newStr.length();
}

LoserSed::~LoserSed(){};

void LoserSed::newFile()
{
    std::ifstream ifs(this->_filename.c_str());
    std::ofstream ofs((this->_filename + ".replace").c_str());
    std::string   str;
    std::size_t   start;

    if (!ifs.is_open() || !ofs.is_open()) 
    {
        std::cerr << "Error\nFailed opening the file" << std::endl;
        return ;
    }
    while (std::getline(ifs, str))
    {
        start = 0;
        while ((start = str.find(this->_oldString, start)) != std::string::npos)
        {
            str = str.substr(0, start) + this->_newString + str.substr(start + this->_oldStringSize);
            start += this->_newStringSize;
        }
        ofs << str << std::endl;
    }
    ifs.close();
    ofs.close();
}