#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int main()
{
    /* Declaracion de una nueva estructura que sera
     * utilizada como un nuevo tipo de variable */
    struct Examen_t {
        char        Carnet[10];
        unsigned    Nota;
        bool        Aprobado;
    };

    /* Examen_t es un nuevo tipo, y puede ser usado 
     * para definir variables individuales, o como
     * en este ejemplo, un arreglo */
    Examen_t Primer_parcial[3];

    /* La asignacion debe hacerce para cada elemnto
     * del arreglo. */
    strcpy(Primer_parcial[0].Carnet, "199516766");
    Primer_parcial[0].Nota = 61;
    Primer_parcial[0].Aprobado = true;

    strcpy(Primer_parcial[1].Carnet, "200516766");
    Primer_parcial[1].Nota = 51;
    Primer_parcial[1].Aprobado = false;

    strcpy(Primer_parcial[2].Carnet, "201516766");
    Primer_parcial[2].Nota = 71;
    Primer_parcial[2].Aprobado = true;

    cout<< setw(12) << "Carnet"
        << setw(7)  << "Nota"
        << setw(13) << "Estado" << endl;

    for( int i = 0; i < 3; i++ )
    {
        cout<< setw(12) << Primer_parcial[i].Carnet
            << setw(7)  << Primer_parcial[i].Nota;

        if( Primer_parcial[i].Aprobado )
            cout << setw(13) << "APROBADO" << endl;
        else
            cout << setw(13) << "REPROBADO" << endl;
    }    
    
    return 0;
}