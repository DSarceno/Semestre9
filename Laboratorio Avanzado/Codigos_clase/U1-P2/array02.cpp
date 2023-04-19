#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    /* Declaracion de un array 5 de enteros inicializados */
    int     a2[5] = { 1, 2, 3 ,4 , 5};
    /* a2 contiene la direccion del inicio del bloque,
     * esta se puede asignar a un puntero del mismo tipo 
     * del arreglo. */
    int*    p = a2;

    cout<< "a2: " << a2 << endl << endl;

    cout<< "i"   << setw(5)
        << "*p"  << setw(20)
        << "p++" << endl;

    /* Los punteros se pueden incrementar y obtener el
     * valor de donde apuntan. */
    for( int i = 0; i< 5; i++)
        cout<< i     << setw(5)
            << *p    << setw(20)
            << p++   <<  endl;

    return 0;
}