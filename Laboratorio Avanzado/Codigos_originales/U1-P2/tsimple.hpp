/* 
 * tsimple.hpp: Definicion e implementacion del 
 * template tsimple
 * 
 * Ejemplo para la parte III del curso introductorio
 * de ROOT.
 * 
 * Hector Perez, abril 2020
 * 
 */

#ifndef __TSIMPLE_HPP__
#define __TSIMPLE_HPP__

#include <string>

/* tsimple: Template de ejemplo. */ 
template< class T>
class tsimple
{
private:
    /* Puntero al atributo del tipo T */
    T* Atributo;

public:
    /* Estos son los metodos del objeto (member functions) */

    /* Constructor sin argumentos */
    tsimple();
    /* Constructor con argumentos */
    tsimple( T Valor );
    /* Destructor */
    ~tsimple();

    /* Metodo para asignar valor (set) */
    int Asignar_Valor( T Valor );
    
    /* Metodo para obtener valor (get) */
    T Obtener_Valor( );

};

/* Implementacion de tsimple.
 * Debido a restricciones del compilador, no es
 * posible separa la definicion del template de 
 * la implementacion. */

/* Constructores */

template< class T>
tsimple< T >::tsimple()
{
    Atributo = 0;
}

template< class T>
tsimple< T >::tsimple( T Valor )
{
    Atributo = new T(Valor);
}

/* Destructor */

template< class T>
tsimple< T >::~tsimple()
{
    delete Atributo;
}

/* Metodo para asignar valor (set) */

template< class T>
int tsimple< T >::Asignar_Valor( T Valor )
{
    if( !Atributo )
        Atributo = new T(Valor);
    else
    {
        std::cout<<"El Valor ya fue asignado" << std::endl;
        return 1;
    }
    return 0;
}

/* Metodo para obtener valor (get) */

template< class T>
T tsimple< T >::Obtener_Valor( )
{
    if( !Atributo )
    {
        std::cout<< "El valor no ha sido asignado" << std::endl;
        /* Como no existe ningun valor asignado y no se sabe
         * el tipo de T, no hay manera de retornar algo, por lo 
         * que se interrumpe la ejecucion del programa. */
        std::exit(1);
    }
    else
        return *Atributo;
    
}


#endif /* __TSIMPLE_HPP__ */