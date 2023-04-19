// vie 14 abr 2023 12:08:40 CST
// hist.C
// Diego Sarceno (dsarceno68@gmail.com)

// Resumen

// Codificado del texto: UTF8
// Compiladores probados: root (Ubuntu 20.04 Linux) 6.28/00 w c++ 9.4.0
// Instruciones de Ejecución: no requiere nada mas
// root -q hist.C

#include "TGraph.h"
#include "TCanvas.h"

#include <cstdlib>
#include <iostream>
#include <fstream>

void hist(){
  fstream f;
  f.open("file6",ios::in);
  int dat;
  TH1D *H1 = new TH1D("H1","Pulsos Dobles, LA-mml-data_1h-180320-182704", 40, 0, 1000);
  int i = 0;
  while (1) {
    f >> dat;
    H1->Fill(dat);
    if (f.eof()) break;
  }
  f.close();
  TCanvas *c1 = new TCanvas();
  H1->Fit("expo","","",100,1000);
  //TFile *afile = new TFile("file1.png","recreate");
  H1->Draw();
  //c1->Update();
  //afile->Close();
}








/*
  EXTRA INFO PARA COMPILACION: (extraido de "LA-mml-data_1h-run.log")
  - File LA-mml-data_1h-180320-173703.paa writted with 59884 pulses
  - File LA-mml-data_1h-180320-174704.paa writted with 59954 pulses
  - File LA-mml-data_1h-180320-175704.paa writted with 61598 pulses
  - File LA-mml-data_1h-180320-180704.paa writted with 60831 pulses
  - File LA-mml-data_1h-180320-181704.paa writted with 60684 pulses
  - File LA-mml-data_1h-180320-182704.paa writted with 60395 pulses
*/
