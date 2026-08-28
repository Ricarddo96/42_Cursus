#include <iostream>
#include <string> 

int main()
{
    std::string brain =  "HI THIS IS BRAIN"; // string con su contenido
    std::string *stringPTR = &brain;         // puntero que guarda la direccion de la string 
    std::string &stringREF = brain;          // referencia: otro nombre para brain (mismo objeto, misma dirección: &stringREF == &brain)

    std::cout << "memory address of brain: " << &brain << std::endl     // imprimimos direccion de brain
    << "memory address of stringPTR: " << stringPTR << std::endl        // stringPTR ya es una variable que guarda la direccion de brain
    << "memory address of stringREF: " << &stringREF << std::endl;      // imprimimos la direccion de memoria de stringREF que es la de brain
    std::cout << "value of brain: " << brain << std::endl               // imprimimos brain
    << "value of stringPTR: " << *stringPTR<< std::endl                 // desreferenciamos stringPTR para acceder al valor que guarda en la memoria 
    << "value of stringREF: " << stringREF << std::endl;                // accedemos a brain por medio de su alias

}