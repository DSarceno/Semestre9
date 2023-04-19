/*
 * clase02.cpp: Programa para mostrar el uso de la
 * clase persona.
 *
 * Ejemplo para la parte III del curso introductorio
 * de ROOT.
 *
 * Hector Perez, abril 2020
 *
 */

#include <cstdlib>
#include <iostream>
#include "persona.hpp"

using namespace std;

/* Programa para mostrar el uso de la clase persona.
 * Se crean instancia y llaman metodos para experimentar
 * que pasa. */
int main()
{
    persona Fulano;

    Fulano.Decir_Nombre();
    Fulano.Decir_origen();
    Fulano.Decir_edad();

    persona Juan("Juan Perez", 1980, 7, 2, "Capital");

    Juan.Decir_Nombre();
    Juan.Decir_origen();
    Juan.Decir_edad();
    Juan.Asignar_DPI("1980130130101");

    persona* Maria = new persona("Maria Gomez", 1990, 12, 3, "Zacapa");

    persona::LLamar_Todos();

    delete Maria;

    persona::LLamar_Todos();

    /* NEW CODE */
    std::string name, birth, year, month, day;
    persona pepe;
    pepe.Asignar_Nombre("Pepe Reyna");
    pepe.Asignar_Lugar_Origen("St. Petersburg");
    pepe.Asignar_Fecha_Nacimiento(1986,5,11);

    name = pepe.Obtener_Nombre();
    std::cout << name << endl; // chequear que se realice imprimiendo el valor
    birth = pepe.Obtener_Lugar_Origen();
    std::cout << birth << endl;

    year = pepe.Obtener_Anio_Nacimiento();
    month = pepe.Obtener_Mes_Nacimiento();
    day = pepe.Obtener_Dia_Nacimiento();
    return 0;
}


















//
