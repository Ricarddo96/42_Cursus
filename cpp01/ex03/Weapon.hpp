#ifndef WEAPON
#define WEAPON

#include <string>

class Weapon 
{
    private:

    std::string type;

    public:

    Weapon(std::string type);
    ~Weapon();
    void setType(std::string type);
    const std::string &getType() const; // el primer const protege el valor retornado (el return es solo de lectura) el segundo protege el objeto que ejecuta el metodo (no modifica ningun atributo interno de la clase)
};


#endif