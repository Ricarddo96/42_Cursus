#ifndef FIXED_HPP
#define FIXED_HPP


class Fixed
{
    public:

    Fixed();
    Fixed(const Fixed &copy); // el const nos asegura que el objeto copiado no se modifica y nos permite copiar objetos const, sin ello solo podriamos copiar objetos modificables
    Fixed &operator=(const Fixed &rsh); // definimos el operador copia como una funcion que mediante referencia accede directamente a los datos de rsh para inyectarlos en el miembro de la izquierda del igual.
    ~Fixed();
    
    int getRawBits( void ) const;
    void setRawBits( int const raw );

    private:

    int value;
    static const int fb; // static aqui indica que el atributo no pertenece a cada instancia individual sino que todas las instancias comparten ese hueco de memoria (no habra un bits para cada instancia sino uno para todas), ademas se puede acceder  a su valor incluso sin instanciar con Fixed::bits

};

#endif