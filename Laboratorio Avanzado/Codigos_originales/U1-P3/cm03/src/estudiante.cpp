/* 
 * persona.cpp: Imprementacion de la clase persona.
 * 
 * Ejemplo para la parte III del curso introductorio
 * de ROOT.
 * 
 * Hector Perez, mayo 2020
 * 
 */

#include <iostream>
#include "estudiante.hpp"


/* Constructor por defecto */
estudiante::estudiante( )
{
    /* Coloca todos los punteros a cero para
     * indicar que no estan asignados */
    Registro_Academico  = 0;
    Fecha_inscripcion   = 0;
    Carrera             = 0;
}

/* Constructor con argumentos */
estudiante::estudiante( std::string    El_Nombre,
                  int            Anio_Nacimiento,
                  int            Mes_Nacimiento,
                  int            Dia_Nacimiento,
                  std::string    Lugar_Origen
            )
        : persona( El_Nombre, Anio_Nacimiento, Mes_Nacimiento, Dia_Nacimiento, Lugar_Origen )
{
    /* El resto de punteros se asigna a cero (NULL) */
    Registro_Academico  = 0;
    Fecha_inscripcion   = 0;
    Carrera             = 0;

}

/* Destructor */
estudiante::~estudiante()
{   
    delete Registro_Academico;
    delete Fecha_inscripcion;
    delete Carrera;
}

/* Metodo para asignar el registro academico (set) */
int estudiante::Asignar_Registro_Academico( std::string Num_RegAcad )
{
    if( !Registro_Academico )
    {
        Registro_Academico = new std::string( Num_RegAcad );
        return 0;
    }
    
    std::cout << "El Registro academico ya fue asignado" << std::endl;
    return 1;
}

/* Metodo para obtener el registro academico (get) */
std::string estudiante::Obtener_Registro_Academico( )
{
    if( Registro_Academico )
        return *Registro_Academico;

    return "Registro academico no asignado";
}

/* Metodo para solicitar que indique su registro
* academico */
void estudiante::Decir_Registro_Academico()
{
    if( Registro_Academico )
        std::cout << "Mi registro academico es: " << *Registro_Academico << std::endl;
    else
        std::cout << "Registro academico no asignado" << std::endl;
}
 /* Sobrecarga del metodo Decir_Nombre */
void estudiante::Decir_Nombre()
{
    if( Nombre )
        std::cout << "Mi Nombre es: " << *Nombre << " y soy estudiante! " << std::endl;
    else
        std::cout << "Nombre no asignado (pero soy estudiante)" << std::endl;
}