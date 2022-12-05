#include <stdio.h>
#define filein "numeri.txt"

int main() {
    FILE *fin;
    int x0,x1,x2,massimo,minimo,scartati=0;
    char flag;
    if ((fin=fopen(filein,"r"))==NULL){
        printf("errore di apertura");
        return 1;
    }
    fscanf(fin,"%d",&x0);
    fscanf(fin,"%d",&x1);
    if(x0>x1){
        massimo=x0;
        minimo=x1;
    }
    else{
        massimo=x1;
        minimo=x0;
    }
    while(fscanf(fin,"%d",&x2)!=EOF){

        if (x0 + x1 == x2 || x0 - x1 == x2 || x1 - x0 == x2 || x1 * x0 == x2 || (x0 / x1 == x2)&& x1 != 0){
            flag='t';
        }

        if (x2>massimo && flag=='t'){
            massimo=x2;
        }
        if(x2<minimo && flag=='t'){
            minimo=x2;
        }
        if (flag=='t'){x0=x1;
            x1=x2;
            flag='f';

        }
        else{
            scartati++;
        }
    }
    printf("Numero massimo: %d\n",massimo);
    printf("Numero minimo: %d\n",minimo);
    printf("Numeri scartati: %d",scartati);

}
