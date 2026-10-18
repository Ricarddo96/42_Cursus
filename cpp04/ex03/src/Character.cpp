#include "../includes/Character.hpp"

Character::Character(std::string name) : name(name)
{
    for (int i = 0; i < 4; i++)
    {
        this->inventory[i] = NULL;
    }
}
Character::Character(const Character &copy) : name(copy.name)
{
    for (int i = 0; i < 4; i++)
    {
        if(copy.inventory[i])
            this->inventory[i] = copy.inventory[i]->clone();
        else
            this->inventory[i] = NULL;
        }
}

Character &Character::operator=(const Character &rsh)
{
    if (this != &rsh)
    {
        this->name = rsh.name;
        for (int i = 0; i < 4; i++)
        {
            delete this->inventory[i];
            if (rsh.inventory[i])
                this->inventory[i] = rsh.inventory[i]->clone();
            else
                this->inventory[i] = NULL;
        }
    }
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++) 
        {
            delete this->inventory[i];
        }
}

std::string const & Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria* m)
{
    if (m)
    {
        for (int i = 0; i < 4; i++)
        {
            if (!this->inventory[i])
            {
                this->inventory[i] = m;
                break;
            }
        }
    }
}
void Character::unequip(int idx)
{
    if (idx < 4 && idx >= 0)
    {
        if (this->inventory[idx])
        {
            this->inventory[idx] = NULL;
        }
    }
    
}
void Character::use(int idx, ICharacter& target)
{
    if (idx < 4 && idx >= 0)
    {
        if (this->inventory[idx])
        {
            this->inventory[idx]->use(target);
        }
    }
}