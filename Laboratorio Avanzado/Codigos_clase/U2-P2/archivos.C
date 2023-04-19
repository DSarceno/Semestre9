/*
 * archivos.C: Script de ROOT para mostrar el uso de árboles.
 * 
 * Ejemplo para el curso introductorio de ROOT.
 * Laboratorio Avanzado
 * 
 * Héctor Pérez, marzo 202s.
 * 
 */

#include <iostream>
#include <string>
#include <vector>

#include "TFile.h"
#include "TH1D.h"
#include "TF1.h"
#include "TRandom3.h"

/* Función para crear un histograma y una función y
 * guardarlas en un archivo */
void WriteData(const char* NombreDelArchivo)
{
    
    /* Se abre un archivo donde se guardardan los datos */
    TFile *aFile = new TFile(NombreDelArchivo,"recreate");
    
    /* Se crea un histograma y se llena con números aleatorios */
    TH1D *aHist = new TH1D("h1","A histogram",100,-3,3);
    aHist->FillRandom("gaus",10000);

    /* Se escribe el histograma en el archivo */
    aHist->Write();

    /* Se define una función */
    TF1 *PicoLorentziano = new TF1("PL","([0]/TMath::Pi())*([1]/((x-[2])*(x-[2])+[1]*[1]))",0,10);
    PicoLorentziano->SetParNames("Amplitud","FWHM","mean");
    PicoLorentziano->SetParameters(20,1,4);

    /* SE guarda la función en el archivo */
    PicoLorentziano->Write();

    /* Se cierra el archivo */
    aFile->Close();

}

/* Esta función obtiene el histograma del archivo */
void ReadHist(const char * NombreDelArchivo)
{
    /* Primero se abre el archivo para lectura */
    TFile *oFile = new TFile(NombreDelArchivo);

    if(!oFile)
    {
        std::cout<<"No fue posible abrir el archivo "<< NombreDelArchivo << std::endl;
        return;
    }

    /* Se crea un puntero de histograma para cargar los datos 
     * del archivo */
    TH1D *oHist;

    /* Se busca el histograma en el archivo. Nótese que se debe
     * saber el nombre del histograma que se desea cargar. */
    oHist = (TH1D*)oFile->Get("h1");

    /* Se dibuja el histograma */
    oHist->Draw();

}

/* Esta función obtiene la función del archivo */
void ReadFunc(const char * NombreDelArchivo)
{
    /* Primero se abre el archivo para lectura */
    TFile *oFile = new TFile(NombreDelArchivo);

    if(!oFile)
    {
        std::cout<<"No fue posible abrir el archivo "<< NombreDelArchivo << std::endl;
        return;
    }

    /* Se crea un puntero de histograma para cargar los datos 
     * del archivo */
    TF1 *oFunc;

    /* Se busca el histograma en el archivo. Nótese que se debe
     * saber el nombre del histograma que se desea cargar. */
    oFunc = (TF1*)oFile->Get("PL");

    /* Se dibuja el histograma */
    oFunc->Draw();

}