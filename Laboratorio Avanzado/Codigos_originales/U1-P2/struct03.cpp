#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    /* A continuacion se utiliza la forma completa de struct.
     * Sin embargo, es poco frecuente utilizala. */
    struct Examen_t {
        char        Carnet[10];
        unsigned    Nota;
        bool        Aprobado;
    } Examen;

    /* El tener la estructura como un tipo tambien
     * permite definir punteros a estas. */
    Examen_t* P2Examen = &Examen;

    /* La forma de acceder a los campos de la estructura
     * desde un puntero es por medio de -> en lugar de . */
    strcpy(P2Examen->Carnet, "199516766");
    P2Examen->Nota = 61;
    P2Examen->Aprobado = true;

    cout<< "Carnet: "   << P2Examen->Carnet    << endl
        << "Nota: "     << P2Examen->Nota      << endl;
    
    if( P2Examen->Aprobado )
        cout << "APROBADO" << endl;
    else
        cout << "REPROBADO" << endl;
    
    return 0;
}