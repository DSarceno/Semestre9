#include "TF1.h"
#include "TH1D.h"

void RandomGen()
{
    TF1 *FondoCuadratico = new TF1("FC","[0]*x*x+[1]*x+[2]",0,10);
    FondoCuadratico->SetParNames("a","b","c");
    FondoCuadratico->SetParameters(-(4.0/49), 8.0/7, 1.0);

    TF1 *PicoLorentziano = new TF1("PL","([0]/TMath::Pi())*([1]/((x-[2])*(x-[2])+[1]*[1]))",0,10);
    PicoLorentziano->SetParNames("Amplitud","FWHM","mean");
    PicoLorentziano->SetParameters(20,1,4);

    TF1 *Compuesta = new TF1("Comp","FC+PL",0,10);
    
    TH1D *RanHisto = new TH1D("rh","Histograma de numeros aleatorios",200,0,10);
    RanHisto->FillRandom("Comp",1000000);
    RanHisto->Draw();

}

