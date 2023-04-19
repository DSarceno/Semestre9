#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    /* Se reserva un bloque de memoria de 5 enteros */
    int* a = new int[5];

    /* Se puede verificar que la asignacion de mamoria
     * haya sido exitosa antes de continuar */
    if( !a )
    {
        cout << "Asignacion de memoria fallida";
        return 1;
    }

    /* Se puede utilizar a como si fuera un arreglo */
    for( int i = 0; i<5; i++)
        a[i] = i;
    
    /* Tambien se puede usar aritmetica de punteros */
    for( int i = 0; i<5; i++)
        cout<< (*a)++ << endl;

    /* Se libera el espacio de memoria reservado */
    delete a;

    return 0;
}