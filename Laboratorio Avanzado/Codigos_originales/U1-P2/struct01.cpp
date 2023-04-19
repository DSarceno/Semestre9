#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    /* Declaracion de una nueva estructura accesible a
     * travez de la variable Examen */
    struct {
        char        Carnet[10];
        unsigned    Nota;
        bool        Aprobado;
    } Examen;

    /* Los _campos_ de la estructura se llaman por nombre 
     * tanto para asignacion como para lectura */
    strcpy(Examen.Carnet, "199516766");
    Examen.Nota = 61;
    Examen.Aprobado = true;

    cout<< "Carnet: "   << Examen.Carnet    << endl
        << "Nota: "     << Examen.Nota      << endl;
    
    if( Examen.Aprobado )
        cout << "APROBADO" << endl;
    else
        cout << "REPROBADO" << endl;
    
    return 0;
}