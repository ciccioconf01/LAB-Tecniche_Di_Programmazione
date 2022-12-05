#include <stdio.h>

void ruota(int v[], int N, int P, int dir){
    int j , i;
    if (dir == 1){
        for(j=0;j<P;j++){
            int comodo=v[0];
            for(i=0;i<N-1;i++){
                v[i]=v[i+1];
            }
            v[N-1]=comodo;
        }
    }
    if (dir == -1){
        for (j=0;j<P;j++){
            int comodo =v[N-1];
            for(i=N-1;i>0;i--){
                v[i]=v[i-1];
            }
            v[0]=comodo;
        }
    }

}

int main(){
    int N;
    int V[30];
    int i,P,dir;
    do{
        printf("Inserire il valore di N:\n ");
        scanf("%d", &N);
    }while(N>30);
    for (i=0;i<N;i++){
        printf("Inserire il valore %d\n",i);
        scanf("%d",&V[i]);
    }
    do{
        do{
            printf("inserisci il numero di posizioni da ruotare\n");
            scanf("%d",&P);
        }while(P>=N);
        do{
            printf("inserisci 1 per ruotare a sinistra, -1 per ruotare a destra\n");
            scanf("%d",&dir);}
        while(dir!=-1 && dir!=1);
        if(P!=0){
            ruota(V,N,P,dir);
            for (i=0;i<N;i++){
                printf("%d ", V[i]);
            }
            printf("\n");
        }


    }while(P!=0);
}