#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    struct Examen_t {
        char        Carnet[10];
        unsigned    Nota;
        bool        Aprobado;
    };

    /* Ahora se utiliza new para reservar el espacio
     * de memoria de una variable tipo Exament_t. */
    Examen_t* Examen = new Examen_t;

    /* Como Examen ahora es un puntero, se utiliza ->
     * en lugar de . para acceder a los campos. */
    strcpy(Examen->Carnet, "199516766");
    Examen->Nota = 61;
    Examen->Aprobado = true;

    cout<< "Carnet: "   << Examen->Carnet    << endl
        << "Nota: "     << Examen->Nota      << endl;
    
    if( Examen->Aprobado )
        cout << "APROBADO" << endl;
    else
        cout << "REPROBADO" << endl;
    
    /* Se libera el espacio de memoria reservado */
    delete Examen;
    
    return 0;
}