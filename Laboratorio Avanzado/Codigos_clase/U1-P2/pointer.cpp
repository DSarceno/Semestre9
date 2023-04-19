#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    /* Declaracion de una variable entera a */
    int     a = 123;
    /* Declaracion de un puntero p a una variable entera */
    int*    p = 0;

    /* La forma de obtener la direccion de una variable
     * es poner el simbolo & antes de ella. La siguiente
     * linea le asigna a p la direccion de a. 
     */ 
    p = &a;

    /* Se imprimen los valores */
    cout<< "Valor de a: " <<  a << endl;
    cout<< "Valor de p: " <<  p << endl;
    /* Se puede acceder al valor de la variable a traves 
     * de un puntero a ella. Se coloca un * antes del puntero
     */
    cout<< "Valor de a via *p: " <<  *p << endl;

    return 0;
}