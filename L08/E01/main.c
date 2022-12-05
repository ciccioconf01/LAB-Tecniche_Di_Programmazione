#include <stdio.h>


void leggi_matrice(int matrice[][50],int *nr,int *nc){
        FILE *fin;
        int i,j,r,c;
        fin=fopen("mappa.txt","r");
        fscanf(fin,"%d %d",&r,&c);
        *nr=r;
        *nc=c;
        for(i=0;i<*nr;i++){
            for(j=0;j<*nc;j++){
                fscanf(fin,"%d",&matrice[i][j]);
            }
        }
}

int riconosciRegione(int matrice[][50], int nr, int nc, int i, int j, int *b, int *h){
    char flag='f',trovato='f';
    int base=1,altezza=1,salva=j;

    if (matrice[i][j] == 1) {
        if(i==0 && j==0){
            trovato='t';
        }
        else if(i==0){
            if(matrice[i][j-1]==0){
                trovato='t';
            }
        }
        else if(j==0){
            if(matrice[i-1][j]==0){
                trovato='t';
            }
        }
        else{
            if(matrice[i-1][j]==0 && matrice[i][j-1]==0){
                trovato='t';
            }
        }

        if(trovato=='t'){
            while (flag == 'f' && j<=nc) {

                j++;
                if (matrice[i][j] == 1) {
                    base++;
                }
                else {
                    flag = 't';
                }
            }
            flag = 'f';
            j=salva;
                while (flag == 'f' && i<=nr) {
                    i++;
                    if (matrice[i][j] == 1) {
                        altezza++;
                    }
                    else {
                        flag = 't';
                    }
                }


            *b=base;
            *h=altezza;
            return 1;
            }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }
}

int main() {
    int MAXR=50;
    int nr=0,nc=0,b=0,h=0;
    int v1,v2,v3,v4,v5,v6,maxbase=0,maxaltezza=0,maxarea=0;
    int  M[MAXR][50];

    leggi_matrice(M,&nr,&nc);


    for(int r=0;r<nr;r++){
        for(int c=0; c<nc;c++){
            if (riconosciRegione(M,nr,nc,r,c,&b,&h)){
                printf("Il rettangolo con vertice in (%d,%d) ha base = %d e altezza = %d\n",r,c,b,h);

                if(b>maxbase){
                    maxbase=b;
                    v1=r;
                    v2=c;
                }
                if(h>maxaltezza){
                    maxaltezza=h;
                    v3=r;
                    v4=c;
                }
                if((b*h)>maxarea){
                    maxarea=(b*h);
                    v5=r;
                    v6=c;
                }
            }
        }
    }
    printf("\n");
    printf("Altezza massima %d vertice %d %d\n",maxaltezza,v3,v4);
    printf("Base massima %d vertice %d %d\n", maxbase,v1,v2);
    printf("Area massima %d vertice %d %d\n", maxarea,v5,v6);

}
