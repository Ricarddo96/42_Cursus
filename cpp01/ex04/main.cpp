#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    std::ifstream file_1;
    std::ofstream file_2;
    const char* filename;
    std::string outname;
    std::string s1;
    std::string s2;
    std::string line;
    std::string result;
    bool first = true;
    std::size_t start;
    std::size_t pos = 0;

    if (argc != 4 || !argv[1] || !argv[2] || !argv[3])
    {
        std::cerr << "Error: Incorrect number of arguments" << std::endl
        << "Usage: ./loser_sed <file> <s1> <s2>" << std::endl;
        return 1;
    }
    filename = argv[1];
    s1 = argv[2];
    if (s1.empty())
    {
        std::cerr << "Error: s1 cannot be empty" << std::endl;
        return 1;
    }
    s2 = argv[3];
    outname = std::string(filename) + ".replace";
    
    file_1.open(filename);
    if (!file_1.is_open())
    {
        std::cerr << "Error: File 1 opening failed" << std::endl;
        return 1;
    }
    file_2.open(outname.c_str());
    if (!file_2.is_open())
    {
        std::cerr << "Error: File 2 opening failed" << std::endl;
        return 1;
    }
    while (std::getline(file_1, line)) 
    {
        start = 0;
        result = "";
        while ((pos = line.find(s1, start)) != std::string::npos)
        {
            result += line.substr(start, pos - start) + s2;
            start = pos + s1.length();
        }
        result += line.substr(start);
        if (!first)
            file_2 << std::endl;
        file_2 << result;
        first = false;
    }
    return 0;
}