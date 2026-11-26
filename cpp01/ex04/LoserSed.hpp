#ifndef LOSERSED_HPP
# define LOSERSED_HPP

#include <iostream>
#include <string>
#include <fstream>

class LoserSed {
  private:
    std::string _filename;
    std::string _oldString;
    std::string _newString;
    std::size_t _oldStringSize;
    std::size_t _newStringSize;

  public:
    LoserSed(const std::string& filename, const std::string& oldStr, const std::string& newStr);
    ~LoserSed();

    void  newFile();
};

#endif