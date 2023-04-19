/*
 * t1ll3.cpp: Programa para mostrar el uso de la
 * clase VecR3.
 *
 *
 * Diego Sarceno, 201900109
 *
 */

#include <cstdlib>
#include <iostream>

#include "VecR3.hpp"

using namespace std;

/* Inicio del programa, se crean instancias de VecR2
 * y se llaman los metodos. */
int main()
{
    VecR3 v1(1,0,1);
    VecR3 v2(0,1,0);

    cout << "Vectores Utilizados" << endl;
    cout << v1 << endl;
    cout << v2 << endl;

    cout << "Magnitud v1: " << v1.Magnitud() << endl;

    VecR3 v3, v4, v6, v7, v8;
    float c5;
    v3 = v1 + v2;
    cout << "v3 = v1 + v2 = " << v3 << endl;
    v4 = v1 - v2;
    cout << "v4 = v1 + v2 = " << v4 << endl;
    c5 = v1 * v2;
    cout << "c5 = v1 * v2 = " << c5 << endl;
    v6 = v4 + v3 - v1;
    cout << "(Asignar) v6 = v4 + v3 - v1 = " << v6 << endl;
    v7 = 5*v4;
    cout << "v7 = 5*v4 = " << v7 << endl;
    v8 = 5/v4;
    cout << "v8 = 5/v4 = " << v8 << endl;

    return 0;
}
