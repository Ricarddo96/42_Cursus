#ifndef HUMAN_B
#define HUMAN_B

#include <string>
#include "Weapon.hpp"

class HumanB
{
    private:

    std::string name;
    Weapon *weapon;

    public:

    HumanB(std::string name);
    ~HumanB();

    void setWeapon(Weapon &weapon);
    void attack();
};

#endif