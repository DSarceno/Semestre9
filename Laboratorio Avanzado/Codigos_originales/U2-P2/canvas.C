#include "TH1D.h"
#include "TF1.h"
#include "TCanvas.h"

void hSplit()
{
    TF1 *GFunc = new TF1("GF","gaus(0)",-3,3);
    
    TCanvas *aCanvas = new TCanvas("L1","A Canvas",1200,450);
    aCanvas->Divide(2);
    
    TH1D *Hist01 = new TH1D("h1","Frist histogram",100,-3,3);
    GFunc->SetParameters(1,-1,1);
    Hist01->FillRandom("GF",10000);

    aCanvas->cd(1);
    Hist01->Draw();

    TH1D *Hist02 = new TH1D("h2","Second histogram",100,-3,3);
    GFunc->SetParameters(1,1,1);
    Hist02->FillRandom("GF",10000);

    aCanvas->cd(2);
    Hist02->Draw();

    aCanvas->SaveAs("hSplit.pdf");

}

void vSplit()
{
    TF1 *GFunc = new TF1("GF","gaus(0)",-3,3);
    
    TCanvas *aCanvas = new TCanvas("L1","A Canvas",600,900);
    aCanvas->Divide(1,2);
    
    TH1D *Hist01 = new TH1D("h1","Frist histogram",100,-3,3);
    GFunc->SetParameters(1,-1,1);
    Hist01->FillRandom("GF",10000);

    aCanvas->cd(1);
    Hist01->Draw();

    TH1D *Hist02 = new TH1D("h2","Second histogram",100,-3,3);
    GFunc->SetParameters(1,1,1);
    Hist02->FillRandom("GF",10000);

    aCanvas->cd(2);
    Hist02->Draw();

    aCanvas->SaveAs("vSplit.pdf");

}

void hvSplit()
{
    TF1 *GFunc = new TF1("GF","gaus(0)",-3,3);
    
    TCanvas *aCanvas = new TCanvas("L1","A Canvas",1200,900);
    aCanvas->Divide(2,2);
    
    TH1D *Hist01 = new TH1D("h1","Frist histogram",100,-3,3);
    GFunc->SetParameters(1,-1,1);
    Hist01->FillRandom("GF",10000);

    aCanvas->cd(1);
    Hist01->Draw();

    aCanvas->cd(2);
    GFunc->Draw();
    aCanvas->ForceUpdate();

    TH1D *Hist02 = new TH1D("h2","Second histogram",100,-3,3);
    GFunc->SetParameters(1,1,1);
    Hist02->FillRandom("GF",10000);

    aCanvas->cd(3);
    Hist02->Draw();

    aCanvas->cd(4);
    GFunc->Draw();

    aCanvas->SaveAs("hvSplit.pdf");

}