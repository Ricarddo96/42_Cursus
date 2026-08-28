#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main() 
{
  {
    Weapon club = Weapon("crude spiked club");

    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();
  }
  {
    Weapon club = Weapon("crude spiked club");

    HumanB jim("Jim");
    jim.setWeapon(club);
    jim.attack();
    club.setType("some other type of club");
    jim.attack();
  }

  return 0;
}

// El ejercicio enseña a elegir la herramienta según el caso: referencia cuando siempre hay objeto; 
// puntero cuando puede no haberlo o asignarse más tarde.

// recordar: el & si aparece en una declaracion es referencia, si se usa en una expresion es direccion de memoria 