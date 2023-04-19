#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    /* Declaracion de un array 5 de enteros sin inicializar */
    int     a1[5];
    /* Declaracion de un array 5 de enteros inicializados (forma 1 ) */
    int     a2[5] = { 1, 2, 3 ,4 , 5};
    /* Declaracion de un array 5 de enteros inicializados (forma 2 ) */
    int     a3[]  = { 5, 4, 3 ,2 , 1};
    /* Declaracion de un array 5 de enteros inicializados (forma 3 ) */
    int     a4[5]  = { 0 };

    cout<< "i"  << setw(15)
        << "a1" << setw(5)
        << "a2" << setw(5)
        << "a3" << setw(5)
        << "a4" << endl;

    for( int i = 0; i< 5; i++)
        cout<< i     << setw(15)
            << a1[i] << setw(5)
            << a2[i] << setw(5)
            << a3[i] << setw(5)
            << a4[i] << endl;

    return 0;
}