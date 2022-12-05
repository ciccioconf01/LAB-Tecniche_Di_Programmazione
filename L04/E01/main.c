#include <stdio.h>

void sottoSequenze(int V[],int N){
    int i,j,conta=0,massimo=0;
    for(i=0;i<N;i++) {

        if (V[i] != 0) {
            conta++;
        }
        else {
            if (conta > massimo) {
                massimo = conta;
            }
            conta = 0;
        }
    }
    printf("%d\n",massimo);

    conta=0;

    for(i=0;i<N;i++){

        if (V[i] != 0) {
            conta++;
        }
        else {
            if (conta == massimo) {
                printf("[");
                for(j=i-conta;j<i;j++){
                    printf("%d",V[j]);
                }
                printf("] ");
            }
            conta = 0;
        }
    }
}

int main() {
    int N,V[30],i = 0;
    printf("inserisci i numeri (-1 per terminare)\n");
    scanf("%d\n",&V[i]);
    do{
        i++;
        scanf("%d", &V[i]);

    }while (V[i] != -1);
    N=i;
    sottoSequenze(V,N);
}