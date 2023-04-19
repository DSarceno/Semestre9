#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void readfile(const char *filename, const char *outfile);

void thist(){
    readfile("wcd_lago_006-run.log","histogram.txt");
    //return 0;
}
void readfile(const char *filename, const char *outfile){
    float count,rest;
    float cumulative = 0;
    char head[1];

    char content[1471];
    int i=0;
    int c=0;
    TH1F *h1 = new TH1F("h1","hello",10,0,1438);
    
    FILE *file;
    file = fopen(filename,"r");
    
    while(fgets(content, 1471, file)){
    
        sscanf(content, "%s %f %f %f %f %f %f",head, &rest, &rest, &cumulative, &count,&rest, &rest);
        /*
        if(strcmp(head, "I") == 0){
            c++;
            printf("%d \n",c);
            if(c>5)break;
        }*/
        if(strcmp(head, "M") == 0 ){
            
            //printf("%d \t %s \t %f \n",i,head ,count);
            printf("%d \t %f \n",i,count);
            
            h1->SetBinContent(i,count);
            i++;
        }
    }
    
    
    TFile *afile = new TFile(outfile,"recreate");
    h1->Write();
    h1->Draw();
    afile->Close();
    
    
    fclose(file);
}
