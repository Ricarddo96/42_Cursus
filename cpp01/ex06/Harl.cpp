#include "Harl.hpp"
#include <string>
#include <iostream>

Harl::Harl()
{    
}
Harl::~Harl()
{
}

void Harl::debug( void )
{
    std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
    std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning( void )
{
    std::cout << "WARNING: I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void )
{
    std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level )
{
    int i = 0;
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    while (i < 4 && level != levels[i]) 
        i++;
    switch (i) {
        case DEBUG:
            this->debug();
            // fall through
        case INFO:
            this->info();
            // fall through
        case WARNING:
            this->warning();
            // fall through
        case ERROR:
            this->error();
            break;
        default:
            std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
    } 
}