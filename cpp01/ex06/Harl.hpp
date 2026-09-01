#ifndef HARL_HPP
#define HARL_HPP

#include <string>

enum Level
{
    DEBUG = 0,
    INFO = 1,
    WARNING = 2,
    ERROR = 3
};

class Harl
{
    private:

    void debug( void );
    void info( void );
    void warning( void );
    void error( void );

    public:
    
    Harl();
    ~Harl();
    void complain( std::string level );

};


#endif