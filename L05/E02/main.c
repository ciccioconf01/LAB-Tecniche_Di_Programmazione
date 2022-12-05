#include<stdio.h>
#include<string.h>

typedef struct {
    char codifica[30];
    char stringa[20];
}dizionario;

typedef struct {
    int posizione;
    int dimensione;
    int posInDiz;
    char cod[30];
} trovato;

int main(){
    FILE *fin1, *fout;
    dizionario diz[30];
    trovato diz2[30];
    char parola[20];
    char stringa[20];
    int n=0,i=0,j=0,l=0,z=0,r=0,p=1,d=0,h=0;
    if((fin1=fopen("dizionario.txt","r"))==NULL){
        printf("errore di apertura");
        return 0;
    }
    fscanf(fin1,"%d",&n);
    for(i=0;i<n;i++){
        fscanf(fin1,"%s %s\n",diz[i].codifica,diz[i].stringa);
    }
    fclose(fin1);
    if((fin1=fopen("sorgente.txt","r"))==NULL){
        printf("errore di apertura");
        return 1;
    }
    if((fout=fopen("ricodificato.txt","w"))==NULL){
        printf("errore di apertura");
        return 2;
    }
    while(!feof(fin1)){
        fscanf(fin1,"%s\n",parola);
        int x = strlen(parola);
        for(l=0;l<x;l++){



            for(d=0;d<p;d++){
                r=0;
            for(i=d;i<x-l+d;i++){

                stringa[r]=parola[i];
                r++;

            }
            i=d;

            for(j=0;j<n;j++){
                if(strcmp(stringa , diz[j].stringa)==0){
                    diz2[h].posizione=i;
                    diz2[h].dimensione=strlen(diz[j].stringa);
                    diz2[h].posInDiz=j;
                    strcpy(diz2[h].cod,diz[j].codifica);
                    h++;
                }
            }
                for(z=0;z<strlen(parola)-l;z++){
                    stringa[z]='\0';
                }
        }
            p++;

        }

        int ricorda=0;
        if(h>=1){
            if(h==1){
                for(r=0;r<diz2[h-1].posizione;r++){
                    fprintf(fout,"%c",parola[r]);
                }
                fprintf(fout,"%s",diz2[h-1].cod);
                for(r=diz2[h-1].dimensione+r;r<x;r++){
                    fprintf(fout,"%c",parola[r]);
                }
            }
            else{
                int minimo=100000;
                for(r=0;r<h;r++){
                    if(diz2[r].posInDiz<minimo){
                        minimo=diz2[r].posInDiz;
                        ricorda=r;
                    }
                }
                for(r=0;r<diz2[ricorda].posizione;r++){
                    fprintf(fout,"%c",parola[r]);
                }
                fprintf(fout,"%s",diz2[ricorda].cod);
                if(diz2[ricorda].dimensione+diz2[ricorda].posizione<x){
                for(r=diz2[ricorda].dimensione+diz2[ricorda].posizione;r<x;r++){
                    fprintf(fout,"%c",parola[r]);
                }
                }
            }

        }
        else{
            fprintf(fout,"%s",parola);
        }
        fprintf(fout," ");
        h=0;
        p=1;

    }

}