/* 
 * simple.hpp: Definicion de la clase simple
 * 
 * Ejemplo para la parte III del curso introductorio
 * de ROOT.
 * 
 * Hector Perez, abril 2020
 * 
 */

#ifndef __SIMPLE_HPP__
#define __SIMPLE_HPP__

#include <string>

/* Clase simple: Clase de ejemplo. */ 
class simple
{
    /* Tanto los atributos como los metodos pueden ser definidos 
     * privados o publicos. Generalmete los atributos son privados,
     * esto quiere decir que solo es posible acceder a ellos a 
     * traves de los metodos publicos de la clase. */
private:
    /* Estos son los atributos del objeto (data members)
     * Son diferentes para cada instancia de la clase */

    /* Atributo de cada instancia. */
    std::string Frase;

    /* Atributo de clase: es comun a todas las instancias. */
    static int Numero;

public:
    /* Estos son los metodos del objeto (member functions) */

    /* Constructor sin argumentos */
    simple();
    /* Constructor con argumentos */
    simple( std::string La_Frase );
    /* Destructor */
    ~simple();

    /* Metodo para solicitar que imprima la frase.
     * Se llaman a travez de las instancias de la clase */
    void Decir_Frase();
    
    /* Metodo de clase: Indica cuantas instancias estisten
     * de la clase. No puede llamarse desde una instancia */
    static void Cuantos( );

};

#endif /* __SIMPLE_HPP__ */