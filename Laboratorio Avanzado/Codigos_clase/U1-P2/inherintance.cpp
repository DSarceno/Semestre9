/* 
 * inheritance.cpp: Programa para mostrar el uso de la
 * clase estudiante.
 * 
 * Ejemplo para la parte III del curso introductorio
 * de ROOT.
 * 
 * Hector Perez, mayo 2020
 * 
 */

#include <cstdlib>
#include <iostream>
#include "estudiante.hpp"

using namespace std;

/* Programa para mostrar el uso de la clase persona. 
 * Se crean instancia y llaman metodos para experimentar
 * que pasa. */
int main()
{
    estudiante Fulano;

    Fulano.Decir_Nombre();
    Fulano.Decir_origen();
    Fulano.Decir_edad();

    estudiante Juan("Juan Perez", 1980, 7, 2, "Capital");
    
    Juan.Decir_Nombre();
    Juan.Decir_origen();
    Juan.Decir_edad();
    Juan.Asignar_DPI("1980130130101");

    estudiante* Maria = new estudiante("Maria Gomez", 1990, 12, 3, "Zacapa");

    Maria->Decir_Nombre();
    Maria->Asignar_Registro_Academico("202012345");
    Maria->Decir_Registro_Academico();

    estudiante::LLamar_Todos();


    return 0;
}