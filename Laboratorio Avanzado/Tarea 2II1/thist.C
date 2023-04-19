#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void readfile(const char *filename, const char *outfile);

void thist(){
    readfile("wcd_lago_006-run.log","histogram.pdf");
    //return 0;
}
void readfile(const char *filename, const char *outfile){
    float count,rest;
    float cumulative = 0;
    char head[1];

    char content[1471];
    int i=0;
    int c=0;
    TH1F *H1 = new TH1F("Data","Detector Cherenkov de Agua",10,0,1438);

    FILE *file;
    file = fopen(filename,"r");

    while(fgets(content, 1471, file)){

        sscanf(content, "%s %f %f %f %f %f %f",head, &rest, &rest, &cumulative, &count,&rest, &rest);

        if(strcmp(head, "M") == 0 ){

            printf("%d \t %f \n",i,count);

            H1->SetBinContent(i,count);
            i++;
        }
    }


    TFile *afile = new TFile(outfile,"recreate");
    H1->Write();
    H1->Draw();
    afile->Close();


    fclose(file);
}
