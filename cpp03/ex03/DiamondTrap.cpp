#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(30);
    std::cout << "DiamondTrap constructor called" << std::endl;
}
/* 
Al haber configurado la herencia como virtual, la regla de C++ cambia radicalmente 
para la clase base raíz (ClapTrap).

Regla normal: Normalmente, las clases hijas llaman a los constructores de sus padres directos.

Excepción de la herencia virtual: Cuando hay herencia virtual,
la clase más derivada (la última de la cadena, es decir, DiamondTrap) 
es la única encargada de inicializar directamente a la clase base virtual (ClapTrap).

ClapTrap(name + "_clap_name"): DiamondTrap salta por encima de FragTrap y ScavTrap y 
le inyecta el nombre con sufijo directamente a la abuela (ClapTrap). 
Si no lo hicieras tú aquí, C++ intentaría llamar al constructor por defecto de ClapTrap.

FragTrap(name) y ScavTrap(name): Aunque FragTrap y ScavTrap también tienen sus propios constructores 
que intentarán inicializar a ClapTrap, C++ es inteligente y, gracias a que es virtual, 
ignora los intentos de FragTrap y ScavTrap de tocar a ClapTrap, 
quedándose únicamente con el que le pasó DiamondTrap. 
Aun así, tienes que llamarlos porque forman parte de la cadena de construcción */


DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), FragTrap(copy), ScavTrap(copy), _name(copy._name)
{
    std::cout << "Copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rsh)
{
    if (this != &rsh)
    {
        ClapTrap::operator=(rsh);
        this->_name = rsh._name;
    }
    std::cout << "DiamondTrap asignment operator called" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "My DiamondTrap name: " << this->_name << " || My ClapTrap name: " << ClapTrap::getName() << std::endl;
}