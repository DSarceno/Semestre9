/* 
 * estuciante.hpp: Definicion de la clase estudiante.
 * 
 * Ejemplo para la parte III del curso introductorio
 * de ROOT.
 * 
 * Hector Perez, mayo 2020
 * 
 */

#ifndef __ESTUDIANTE_HPP__
#define __ESTUDIANTE_HPP__

#include <string>
#include <ctime>

#include "persona.hpp"

/* Clase estudiante. Almacena los datos basicos de un estudiante.
 * Hereda de la clase persona. */
class estudiante : public persona
{
protected:
    /* Atributos. Estos atributos extienden los
     * que ya posee la clase persona */

    /* Registro academico */
    std::string* Registro_Academico;
    /* Fecha de inscripcion */
    std::tm*     Fecha_inscripcion;
    /* Carrera */
    std::string* Carrera;

public:
    /* Metodos */

    /* Constructor por defecto */
    estudiante();
    /* Constructor con argumentos */
    estudiante( std::string    El_Nombre,
             int            Anio_Nacimiento,
             int            Mes_Nacimiento,
             int            Dia_Nacimiento,
             std::string    Lugar_Origen
            );

    /* Destructor */
    ~estudiante();

    /* Metodo para asignar el registro academico (set) */
    int Asignar_Registro_Academico( std::string Num_RegAcad );

    /* Metodo para obtener el registro academico (get) */
    std::string Obtener_Registro_Academico( );
    
    /* Metodo para solicitar que indique su registro
     * academico */
    void Decir_Registro_Academico();

    /* Sobrecarga del metodo Decir_Nombre */
    void Decir_Nombre();

};


#endif /* __ESTUDIANTE_HPP__ */