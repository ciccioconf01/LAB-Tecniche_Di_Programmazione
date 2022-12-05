#include <stdio.h>

int main(){
    FILE* fin;
    char nome[20];
    int matrice[20][20], vettore[20], matriceMax[30];
    int i,j,f=0,l=0,nr,nc, minimo,massimo=0, valore,k,x,acc=0,scelta,temp;
    printf("Inserire il nome del file da aprire: ");
    gets(nome);
    if((fin=fopen(nome,"r"))==NULL){
        printf("errore di apertura");
        return 0;
    }
    fscanf(fin,"%d%d\n",&nr, &nc);
    for ( i=0;i<nr;i++){
        for ( j=0;j<nc;j++){
            fscanf(fin,"%d", &matrice[i][j]);
        }
    }
    minimo=(nr<nc)? nr:nc;
    printf("inserisci un valore compreso fra 1 e %d ",minimo);
    scanf("%d",&valore);
    scelta=valore;
    while (valore>0 && valore<=minimo){
        for(i=0;i<nr-valore+1;i++){
            for(j=0;j<nc-valore+1;j++){
                for(k=0;k<valore;k++){
                    for(x=0;x<valore;x++){
                        printf("%d",matrice[i+k][j+x]);
                        acc=acc+matrice[i+k][j+x];
                        vettore[f]=matrice[i+k][j+x];
                        f++;
                    }
                    printf("\n");
                }
                printf("\n");
                if(acc>massimo){
                    massimo=acc;
                    if (minimo != temp){
                        temp = minimo;
                    }
                    for(l=0;l<temp*temp;l++){
                        matriceMax[l]=vettore[l];
                    }
                }
                f=0;
                acc=0;
            }

        }
        printf("inserisci un valore compreso fra 1 e %d ",minimo);
        scanf("%d",&valore);
        if(valore>minimo){
            printf("La sottomatrice con somma degli elementi massima (%d) e':\n",massimo);
            for(l=0;l<temp*temp;l++){
                printf("%d",matriceMax[l]);
                if((l+1)%temp==0){
                    printf("\n");
                }
            }
        }
    }
}