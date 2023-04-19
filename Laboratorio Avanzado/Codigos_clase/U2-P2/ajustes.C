/*
 * ajustes.C: Muestra como llenar un histograma
 * con números aleatorios generados a partir
 * de una función definida y luego hacer un ajuste
 * con esta misma función.
 *
 * Ejemplo para el curso introductorio de ROOT.
 * Laboratorio Avanzado
 *
 * Héctor Pérez, marzo 2022.
 *
 */

#include "TROOT.h"
#include "TH1D.h"
#include "TF1.h"
#include "TFitResult.h"

/* Función de pico Lorentziano mas
 * fondo cuadrático (definición por
 * medio de funcion C/C++ tradicional */
Double_t MiFuncion( Double_t x,
                    Double_t a,
                    Double_t b,
                    Double_t c,
                    Double_t An,
                    Double_t gamma,
                    Double_t mu)
{
    return  a*TMath::Power(x,2) + b*x + c
            + (An/TMath::Pi())*(gamma/(TMath::Power(x-mu,2)+TMath::Power(gamma,2)));
}

void Ajuste()
{
    /* Función de pico Lorentziano mas fondo cuadrático
     * (definición por medio de constructores de ROOT) */
    TF1 *Fondo_Cuadratico = new TF1("FC","[0]*x*x+[1]*x+[2]",0,10);
    Fondo_Cuadratico->SetParNames("a","b","c");
    Fondo_Cuadratico->SetParameters(-(4.0/49),(8.0/7),1);

    TF1 *Lorentziana = new TF1("FL","([0]/TMath::Pi())*([1]/((x-[2])*(x-[2]) + [1]*[1]))",0,10);
    Lorentziana->SetParNames("Amplitud","FWHM","Media");
    Lorentziana->SetParameters(20,1,4);

    TF1 *Funcion01 = new TF1("Func01","FC + FL",0,10);
    // Funcion01->Draw();

    /* LLenado de un histograma con números aleatorios conforme a
     * la función predefinada */
    TH1D *Histo = new TH1D("h1","Histograma con numeros aleatorios",100,0,10);
    Histo->FillRandom("Func01",10000);
    // Histo->Draw();

    /* Definición de una TF1 que utiliza la función tradicional de
     * C/C++ */
    TF1 *Funcion02 = new TF1("Func02","MiFuncion(x,[0],[1],[2],[3],[4],[5])",0,10);
    Funcion02->SetParNames("a","b","c","An","gamma","mu");
    // Funcion02->SetParameters(-3.57,37,19,10,1,5);
    // Funcion02->Draw();

    /* Ajuste de la función a los datos en el histograma */
    Histo->Fit("Func02");
    // TFitResultPtr resultados = Histo->Fit("Func02","QS");
    // resultados->Print("V");
    // std::cout<< "Chi2/NDF: " << resultados->Chi2()/resultados->Ndf() << std::endl;
    // std::cout<< "a: " << resultados->Parameter(0) << std::endl;
    // std::cout<< "error en a: " << resultados->ParError(0) << std::endl;
    }