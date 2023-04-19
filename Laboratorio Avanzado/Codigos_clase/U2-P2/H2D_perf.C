/*
 * H2D_perf.C: Script de ROOT para mostrar el uso de histogramas
 * en 2D y perfiles.
 * 
 * Ejemplo para el curso introductorio de ROOT.
 * Laboratorio Avanzado
 * 
 * Héctor Pérez, mayo 2020.
 * 
 */

#include <iostream>

#include "TF2.h"
#include "TH2D.h"
#include "TProfile.h"
#include "TMath.h"
#include "TCanvas.h"

/* Esta función muestra en pantalla una función en dos dimensiones,
 * un histograma de dos dimensiones construido con números aleatórios
 * a partir de la función y los perfiles x y y de este histograma.
 */
void H2D_perf_Func()
{
    /* Se define la función para llenar el histograma den 2D, esta
     * es del tipo TF2, es decir, debe tomar dos argumentos. */
    TF2 *aFunc = new TF2("f2d",
                         "[0]*exp(-1*(y-x-[1])*(y-x-[1])/(2*[2]*[2]))",
                         0,1,0,2);
    aFunc->SetParNames("Amp","xShift","Dev");
    aFunc->SetParameters(1,0.5,0.1);

    /* Se crea una instancia a un histograma en 2 dimensiones. */
    TH2D *rHisto = new TH2D("rh","Histograma de numeros aleatorios",200,0,1,200,0,2);
    rHisto->FillRandom("f2d",10000);

    /* Se hace un perfil de los datos en x */
    TProfile *xProf = rHisto->ProfileX("rh_xp");
    /* Se hace un perfil de los datos en x */
    TProfile *yProf = rHisto->ProfileY("rh_yp");

    /* Se crea un canvas para mostrar las gráficas de la función y del
     * histograma aleatorio. */
    TCanvas *aCanvas = new TCanvas("C1","Ejemplo Script02",700,700);
    aCanvas->Divide(2,2);

    /* Se hacen las gráficas en los TPads */
    /* Primer TPad */
    aCanvas->cd(1);
    aFunc->Draw("surf1");

    /* Segundo TPad */
    aCanvas->cd(2);
    rHisto->Draw();

    /* Tercer TPad */
    aCanvas->cd(3);
    xProf->Draw();

    /* Cuarto TPad */
    aCanvas->cd(4);
    yProf->Draw();

}

/* Esta función limpia las asignaciones de memoria hechas por 
 * Script01Func(). */
void H2D_perf_Clean()
{
    void *ptr;
    if( (ptr = gDirectory->FindObject("f2d")) )   delete (TF2*)ptr;
    if( (ptr = gDirectory->FindObject("rh")) )    delete (TH2D*)ptr;
    if( (ptr = gDirectory->FindObject("rh_xp")) ) delete (TProfile*)ptr;
    if( (ptr = gDirectory->FindObject("rh_yp")) ) delete (TProfile*)ptr;
    if( (ptr = gDirectory->FindObject("C1")) )    delete (TCanvas*)ptr;
}
