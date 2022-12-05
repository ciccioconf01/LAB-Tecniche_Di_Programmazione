#include <stdio.h>
typedef struct {
int riga_sup;
int colonna_sup;
int base;
int altezza;
int area;
} salva;


int main() {
    FILE *fin;

    int nr,nc,i,j,r,x,d, matrice[50][50];
    int base=1, altezza=1, massimo_h=0,massimo_b=0, massimo_a=0;
    salva tabella[50];

    char flag='f',trovato='f';
    if((fin=fopen("mappa.txt","r"))==NULL){
        printf("errore");
        return 1;
    }

    fscanf(fin,"%d %d",&nr,&nc);
    if(nr>50 || nc>50){
        printf("la matrice è sovradimensionata");
        return 2;
    }

    for(i=0;i<nr;i++){
        for(j=0;j<nc;j++){
            fscanf(fin,"%d",&matrice[i][j]);
        }
    }

    for(i=0;i<nr;i++) {
        for (j = 0; j < nc; j++) {
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

                tabella[r].riga_sup = i;
                tabella[r].colonna_sup = j;
                while (flag == 'f') {
                    j++;
                    if (matrice[i][j] == 1) {
                        base++;

                        d++;
                    } else {
                        flag = 't';
                    }

                }   flag = 'f';
                    j = tabella[r].colonna_sup;
                    while (flag == 'f') {
                        i++;
                        if (matrice[i][j] == 1) {
                            altezza++;

                            d++;
                        } else {
                            flag = 't';
                        }
                    }
                    flag='f';
                i = tabella[r].riga_sup;

                tabella[r].base=base;
                tabella[r].altezza=altezza;
                tabella[r].area=tabella[r].base*tabella[r].altezza;
                r++;
                base=1;
                altezza=1;

            }

        }
            trovato='f';
        }
    }

    for(x=0;x<r;x++){
        if (tabella[x].base>massimo_b){
            massimo_b=tabella[x].base;
            i=x;
        }
        if (tabella[x].altezza>massimo_h){
            massimo_h=tabella[x].altezza;
            j=x;
        }
        if (tabella[x].area>massimo_a){
            massimo_a=tabella[x].area;
            d=x;
        }
    }
    printf("Max Base: estr. sup. SX=<%d,%d> b=%d, h=%d, Area=%d\n",tabella[i].riga_sup,tabella[i].colonna_sup,tabella[i].base,tabella[i].altezza,tabella[i].area);
    printf("Max Area: estr. sup. SX=<%d,%d> b=%d, h=%d, Area=%d\n",tabella[d].riga_sup,tabella[d].colonna_sup,tabella[d].base,tabella[d].altezza,tabella[d].area);
    printf("Max Altezza: estr. sup. SX=<%d,%d> b=%d, h=%d, Area=%d",tabella[j].riga_sup,tabella[j].colonna_sup,tabella[j].base,tabella[j].altezza,tabella[j].area);

}
