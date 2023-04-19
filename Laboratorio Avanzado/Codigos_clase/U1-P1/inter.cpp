#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    int       Var1, Var2, Var3;

    /* Estas son tres formas de asignar valor a una variable.
     * Notese que en este caso las variables tipo int son 
     * de 4 bytes o 32 bits. */
    // Binario
    Var1 = 0b11001111001010101011001100111010;
    // Hexadecimal
    Var2 = 0xcf2ab33a;
    // Decimal
    Var3 = -819285190;

    cout << Var1 << endl;
    cout << Var2 << endl;
    cout << Var3 << endl;

    /* En el caso de variables enteras es posible reinterpretar el 
     * valor asignado de memoria a enteras con/sin signo de manera simple */

    cout << (unsigned int) Var1 << endl;

    /* En el caso de enteras a flotantes, con este mismo método se realiza 
     * una conversión de tipo, no una reinterpretación del valor asignado 
     * en memoria */
    
    cout << (float) Var1 << endl;

    /* Cualquier variable puede ser utilizada como tipo booleano, si su
     * valor es cero se interpreta como false, en cualquier otro caso,
     * como true */

    if( Var1 )
        cout << "true" << endl;
    else
        cout << "false" << endl;
    
    Var1 = 0;

    if( Var1 )
        cout << "true" << endl;
    else
        cout << "false" << endl;

    
    /* La asignasión binaria o hexadecimal funciona con otros tipos de variable,
     * solo hay que tener cuidado con el número de bits. */
     
    float Var4 = 0b11001111001010101011001100111010;

    /* Notese que el valor asignado a memoria fue el mismo que a Var1, pero
     * ahora este si se interpreta de forma diferente. */
    
    cout << Var4 << endl;

    return 0;
}