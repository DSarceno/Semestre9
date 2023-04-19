/* 
 * class03.cpp: Programa para mostrar el uso de la
 * clase VecInt2R.
 * 
 * Ejemplo para la parte III del curso introductorio
 * de ROOT.
 * 
 * Hector Perez, abril 2020
 * 
 */

#include <cstdlib>
#include <iostream>

#include "VecR2.hpp"

using namespace std;

/* Inicio del programa, se crean instancias de VecR2
 * y se llaman los metodos. */
int main()
{
    VecR2 v1(1,0);
    VecR2 v2(0,1);

    cout<<  "v1 = " <<  v1 << endl;
    cout<<  "Magnitud de v1: " << v1.Magnitud() << endl;

    cout<<  "v2 = " <<  v2 << endl;

    VecR2 v3;

    v3 = v1 + v2;

    cout << "v3 = v1 + v2 = " << v3 << endl;

    VecR2 v4;

    v4 = v1 + 2*v2;

    cout << "v4 = v1 + 2*v2 = " << v4 << endl;

    cout << "Producto punto" << endl;
    cout << "v1*v2 = " << v1*v2 << endl;
    cout << "v3*v4 = " << v3*v4 << endl;

    VecR2::Mostar_Polar(true);
    cout<< "Mostar en notacion polar activado" << endl;
    cout<<  "v1 = " <<  v1 << endl;
    cout<<  "v2 = " <<  v2 << endl;
    cout << "v3 = " <<  v3 << endl;
    cout << "v4 = " <<  v4 << endl;


    return 0;
}