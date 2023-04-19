/* 
 * VecR2.cpp: Implementacion de la clase VecR2
 * 
 * Ejemplo para la parte III del curso introductorio
 * de ROOT.
 * 
 * Hector Perez, abril 2020
 * 
 */

#include <iostream>
#include <cmath>

#include "VecR2.hpp"

bool VecR2::Polar = false;

VecR2::VecR2( )
{
    Xcor = 0;
    Ycor = 0;
}

VecR2::VecR2( float valor_x, float valor_y )
{
    Xcor = valor_x;
    Ycor = valor_y;
}

VecR2::~VecR2()
{}

void VecR2::Asignar_x( float valor_x )
{
    Xcor = valor_x;
}

void VecR2::Asignar_y( float valor_y )
{
    Ycor = valor_y;
}

void VecR2::Asignar_xy( float valor_x, float valor_y )
{
    Xcor = valor_x;
    Ycor = valor_y;
}

float VecR2::Obtener_x( ) const
{
    return Xcor;
}

float VecR2::Obtener_y( ) const
{
    return Ycor;
}

float VecR2::Magnitud() const
{
    return std::sqrt( Xcor*Xcor + Ycor*Ycor );
}

/* Sobrecarga de operadores */

/* Calcula la suma de dos vectores */
VecR2 VecR2::operator+( const VecR2 &avec) const
{
    /* Se declara un vector temporal para almacenar los resultados */
    VecR2 tmp;
    /* Uno de los vectores a sumar es el que llama el operador,
     * por lo que se accede a el por el puntero "this". El otro
     * es el que se pasa como argumento.
     * Como se esta dentro de las definiciones de clase, se puede
     * acceder a los atributos privados. */
    tmp.Xcor = this->Xcor + avec.Xcor;
    tmp.Ycor = this->Ycor + avec.Ycor;

    /* Se devuelve la suma de los vectores */
    return tmp;
}

/* Calcula el producto punto de dos vectores */
float VecR2::operator*( const VecR2 &avec ) const
{
    /* Ver los comentarios de operator+ */
    float tmp;

    tmp = this->Xcor * avec.Xcor + this->Ycor * avec.Ycor;

    return tmp;
}

/* Operador de asignacion */
VecR2 VecR2::operator=( const VecR2 &avec)
{
    /* El vector que llama el operador es el que 
     * esta al lado izquierdo de este, y el que
     * esta al lado derecho se pasa como argumento
     * por lo que a "this" se le debe asignar el 
     * valor del argumento */
    this->Xcor = avec.Xcor;
    this->Ycor = avec.Ycor;

    return (*this);
}

/* Metodo de clase: Fija el valor del flag para que
 * el despliege del vector sea en polar (true) o
 * cartesiano (false) */
void VecR2::Mostar_Polar( bool valor )
{
    Polar = valor;
}

/* Funciones amigas. 
 * Estas funciones fueron declarada como amigas (friend) en la 
 * definicion de la clase. Las funciones amigas no son metodos 
 * de los objetos, pero pueden acceder a los atributos privados de
 * estos.*/

/* Despliega un vector con cout */
std::ostream &operator<<( std::ostream &salida, const VecR2 &avec )
{
    /* Se decide el tipo de salida en funcion del valor del atributo
     * de clase Polar. */
    if( VecR2::Polar )
    {
        /* Se calcula el angulo polar del vector. La magnitud
         * se obtiene del metodo ya implementado */
        float ang = std::atan2( avec.Ycor , avec.Xcor );
        salida << "( " << avec.Magnitud() << " < " << ang << " )";
    }
    else
        salida << "( " << avec.Xcor << ", " << avec.Ycor << " )";
    
    return salida;
}

/* Esta funcion sobrecarga el operador* para permitir
 * la multiplicacion de un escalar por un vector
 * de la forma aesc*avec. Es importante hacer notar
 * que el orden de la multiplicacion NO ES CONMUTATIVO,
 * es decir, esta funcion no es llamada si el orden
 * escalar * vector es invertido. */
VecR2 operator*( const float &aesc, const VecR2 &avec )
{
    VecR2 tmp;
    tmp.Xcor = aesc*avec.Xcor;
    tmp.Ycor = aesc*avec.Ycor;

    return tmp;
}