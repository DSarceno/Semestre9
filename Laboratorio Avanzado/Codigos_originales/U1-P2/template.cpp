/* 
 * template.cpp: Programa para mostrar el uso
 * del template tsimple
 * 
 * Ejemplo para la parte III del curso introductorio
 * de ROOT.
 * 
 * Hector Perez, abril 2020
 * 
 */

#include <iostream>
#include <string>

#include "tsimple.hpp"

using namespace std;

int main()
{
    tsimple<int> itype;
    tsimple<float> ftype;
    tsimple<string> stype;

    itype.Asignar_Valor(1);
    itype.Asignar_Valor(2);

    ftype.Asignar_Valor(1.1);

    stype.Asignar_Valor("Hola mundo");

    cout<< "itype = " << itype.Obtener_Valor() << endl;
    cout<< "ftype = " << ftype.Obtener_Valor() << endl;
    cout<< "stype = " << stype.Obtener_Valor() << endl;

    return 0;

}
