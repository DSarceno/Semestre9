/*
 * script.C: Define la función ScripFunc() que llena
 * un histograma con números aleatorios.
 * 
 * Ejemplo para el curso introductorio de ROOT.
 * Laboratorio Avanzado
 * 
 * Héctor Pérez, mayo 2020.
 * 
 */

/* Los include no son necesarios para las librerías de ROOT
 * o estándar de C++. Sin embargo, son de gran utilidad para
 * que el IDE identifique las clases y haga el realzado de
 * sintaxis, autocompletado y detección de errores. */
#include "TH1D.h"

/* Aunque es posible incluir comandos directamente, lo mejor es
 * definir funciones que se llaman desde el Cling. Esto es mas 
 * entendible y produce menos errores. En este caso se define
 * la función ScriptFunc() que no toma argumentos ni devuelve
 * resultados. Después de descargar el archivo, se debe llamar la
 * función para ejecutarla. */
void Script01Func()
{
    TH1D *RanHisto = new TH1D("rh","Histograma de numeros aleatorios",200,-3,3);
    RanHisto->FillRandom("gaus",10000);
    RanHisto->Draw();
}