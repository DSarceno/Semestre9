/* 
 * class01.cpp: Programa para mostrar el uso de la
 * clase simple.
 * 
 * Ejemplo para la parte III del curso introductorio
 * de ROOT.
 * 
 * Hector Perez, abril 2020
 * 
 */

#include <cstdlib>
#include <iostream>

#include "simple.hpp"

using namespace std;

/* Inicio del programa */
int main()
{
    /* Se crean dos instancias de la clase simple. La 
     * primera sin argumentos, el constructor por defecto
     * es llamando. */
    simple primero;
    /* Para la segunda instancia se utilizan argumentos, el
     * constructor con argumentos es llamado. */
    simple segundo("No estamos en Marte");

    /* Se llama el metodo de clase simple::Cuantos() que
     * nos indica cuantas instancias van de la clase. 
     * Notese que su llamada es independiente de las instancias. */
    simple::Cuantos();

    /* Se crea un puntero a un objeto de tipo simple. Esto
     * no llama al constructor ya que lo que se esta creando
     * es un puntero, no una instancia de clase. */
    simple* tercero = 0;

    /* Se verifica cuantas instancias van. */
    simple::Cuantos();

    /* Se crea una instancia en memoria de la clase simple
     * utilizando new. La ubicacion de esta clase se almacena
     * en el puntero creado anteriormente. Notese que se
     * llama la forma con argumentos. */
    tercero = new simple("Voy de ultimo");

    /* Se verifica cuantas instancias van. */
    simple::Cuantos();

    /* Se llaman los metodos de los objetos. Estos deben
     * ser llamados desde una instancia e interactuan
     * con los atributos de cada instancia. */ 
    primero.Decir_Frase();
    segundo.Decir_Frase();
    tercero->Decir_Frase();

    /* Se libera el espacio de memoria creado por new.
     * El destructor es llamado. */
    delete tercero;

    /* Se verifica cuantas instancias van. */
    simple::Cuantos();

    /* Al finalizar la funcion con el comando return
     * las instancias que aun queden deben ser eliminadas. 
     * Los destructores deben ser llamados para cada
     * instancia. */
    return 0;
}