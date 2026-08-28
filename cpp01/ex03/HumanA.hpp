#ifndef HUMAN_A
#define HUMAN_A

#include <string>
#include "Weapon.hpp"


class HumanA 
{
    private:

    std::string name;
    Weapon &weapon_a;

    public:

    HumanA(std::string name, Weapon &weapon_a);
    ~HumanA();

    void attack();
};

#endif