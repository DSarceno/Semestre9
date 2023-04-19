/*
 * arboles.C: Script de ROOT para mostrar el uso de árboles.
 * 
 * Ejemplo para el curso introductorio de ROOT.
 * Laboratorio Avanzado
 * 
 * Héctor Pérez, mayo 2020.
 * 
 */

#include <iostream>
#include <string>
#include <vector>

#include "TTree.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TH1D.h"
#include "TRandom3.h"

/* Función para crear, llenar y guardar un árbol en un archivo */
void WriteTree(const char* NombreDelArchivo)
{
    /* Primero se crean dos variables tipo Double_t que serán 
     * guardadas como ramas en el árbol*/
    Double_t Var_a;
    Double_t Var_b;

    /* Se abre un archivo donde se guardará el árbol */
    TFile *aFile = new TFile(NombreDelArchivo,"recreate");

    /* Se crea una instancia de un árbol*/
    TTree *aTree = new TTree("Arb1","Arbol de ejemplo");

    /* Se crean las ramas de árbol. El primer argumento es
     * el nombre de la rama. Luego la dirección de memoria
     * de la variable/estructura/objeto que se almacenará 
     * en la rama. Por último las hojas y el tipo de dato 
     * que almacenan en formato <nombre_de_hoja>/<tipo>.
     * Cada hoja se separa por : */
    aTree->Branch("Var_a_Branch",&Var_a,"Var_a/D");
    aTree->Branch("Var_b_Branch",&Var_b,"Var_b/D");

    /* Se llena el árbol con 1000 entradas aleatorias */
    for(Int_t i = 0; i<1000; i++)
    {
        Var_a = gRandom->Gaus();
        Var_b = gRandom->Gaus();
        aTree->Fill();
    }

    /* Se escribe el árbol en el archivo */
    aTree->Write();

    /* Se cierra el archivo */
    aFile->Close();

}

/* Esta función lee un árbol de un archivo y un histograma
 * para cada rama del árbol */
void ReadTree(const char * NombreDelArchivo)
{
    /* Primero se abre el archivo para lectura */
    TFile *oFile = new TFile(NombreDelArchivo);

    if(!oFile)
    {
        std::cout<<"No fue posible abrir el archivo "<< NombreDelArchivo << std::endl;
        return;
    }

    /* Se crea un puntero de árbol para cargar los datos 
     * del archivo */
    TTree *oTree;

    /* Se busca el árbol en el archivo. Nótese que se debe
     * saber el nombre del árbol que se desea cargar. */
    oTree = (TTree*)oFile->Get("Arb1");

    /* Para cargar los datos del árbol, se debe conocer la
     * estructura con que este fue creado, ya que se deben 
     * extraer los datos de la misma forma.  Se crean un 
     * par de variables Double_t donde se colocarán los datos .*/
    Double_t Var_A;
    Double_t Var_B;

    /* Se asocian las direcciones de estas variables con las
     * ramas. */
    oTree->SetBranchAddress("Var_a_Branch",&Var_A);
    oTree->SetBranchAddress("Var_b_Branch",&Var_B);

    /* Se obtiene el número de entradas */
    Long_t Entradas = (Long_t)oTree->GetEntries();

    /* Se crean las instancias de los histogramas */
    TH1D *Hist_A = new TH1D("Ha","Datos rama Var_a",100,0,0);
    TH1D *Hist_B = new TH1D("Hb","Datos rama Var_b",100,0,0);

    /* Se obtienen los datos */
    for(Long_t i = 0; i<Entradas; i++)
    {
        oTree->GetEntry(i);
        Hist_A->Fill(Var_A);
        Hist_B->Fill(Var_B);
    }
    
    /* Se crea un canvas para mostrar las gráficas de la función y del
     * histograma aleatorio. */
    TCanvas *oCanvas = new TCanvas("C1","Ejemplos de ROOT",800,400);
    /* Se crean 2 pads */
    oCanvas->Divide(2);

    /* Primer TPad */
    oCanvas->cd(1);
    Hist_A->Draw();

    /* Segundo TPad */
    oCanvas->cd(2);
    Hist_B->Draw();

}