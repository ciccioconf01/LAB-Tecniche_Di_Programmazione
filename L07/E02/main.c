#include <stdio.h>

void InsertionSort(int A[], int N) {
    int i, j, l=0, r=N-1, x,n_iterazioni_e=0,n_iterazioni_i=0,n_iterazioni_iTot=0;

    for (i = l+1; i <= r; i++) {
        n_iterazioni_e++;
        x = A[i];
        j = i - 1;
        while (j >= l && x < A[j]){
            n_iterazioni_i++;
            A[j+1] = A[j];
            j--;
        }

        A[j+1] = x;

        printf("Ciclo esterno numero: %d Numero iterazioni ciclo interno = %d\n",n_iterazioni_e,n_iterazioni_i);

        n_iterazioni_iTot=n_iterazioni_iTot+n_iterazioni_i;
        n_iterazioni_i=0;

    }

    printf("Numero totale di scambi = %d\n",n_iterazioni_iTot);
    printf("Numero di iterazioni totali del ciclo esterno = %d\n",n_iterazioni_e);
    printf("Numero di iterazioni totali = %d",n_iterazioni_iTot+n_iterazioni_e);
}

void SelectionSort(int A[], int N) {
    int i, j, l=0, r=N-1, min,n_iterazioni_e=0,n_iterazioni_i=0,scambi=0,n_iterazioni_iTot=0;
    int temp;
    for (i = l; i < r; i++) {
        n_iterazioni_e++;
        min = i;
        for (j = i+1; j <= r; j++){
            n_iterazioni_i++;
            if (A[j] < A[min]){
                min = j;}}
        if (min != i) {
            temp = A[i];
            A[i] = A[min];
            A[min] = temp;
            scambi++;}
        printf("Ciclo esterno numero: %d Numero iterazioni ciclo interno = %d\n",n_iterazioni_e,n_iterazioni_i);

        n_iterazioni_iTot=n_iterazioni_iTot+n_iterazioni_i;
        n_iterazioni_i=0;

    }
    printf("Numero di scambi = %d\n",scambi);
    printf("Numero di iterazioni del ciclo esterno = %d\n",n_iterazioni_e);
    printf("Numero di iterazioni totali = %d",n_iterazioni_iTot+n_iterazioni_e);

    }

void ShellSort(int A[], int N) {
    int i, j, x, l=0, r=N-1, h=1,n_iterazioni_e1=0,n_iterazioni_e2=0,n_iterazioni_i=0,n_iterazioni_iTot=0;
    while (h < N/3)
        h = 3*h+1;
    while(h >= 1) {
        n_iterazioni_e1++;
        for (i = l + h; i <= r; i++) {
            n_iterazioni_e2++;
            j = i;
            x = A[i];
            while(j >= l + h && x < A[j-h]) {
                n_iterazioni_i++;
                A[j] = A[j-h];
                j -=h;

            }
            A[j] = x;

            printf("Ciclo esterno numero: %d Numero iterazioni ciclo interno = %d\n",n_iterazioni_e2,n_iterazioni_i);
            n_iterazioni_iTot=n_iterazioni_iTot+n_iterazioni_i;
            n_iterazioni_i=0;
        }


        h = h/3;
    }
    printf("Numero di scambi = %d\n",n_iterazioni_iTot);
    printf("Numero di iterazioni del ciclo esterno1 = %d\n",n_iterazioni_e1);
    printf("Numero di iterazioni del ciclo esterno2 = %d\n",n_iterazioni_e2);
    printf("Numero di iterazioni totali = %d",n_iterazioni_iTot+n_iterazioni_e1+n_iterazioni_e2);
}

void riempi(int matrice[],int matriceordinata[],int nc){

    for(int x=0;x<nc;x++){
            matrice[x]=matriceordinata[x];

    }
}


int main() {
    FILE *fin;
    int nr,nc,i,j;
    if((fin=fopen("sort.txt","r"))==NULL){
        printf("errore di apertura");
        return 1;
    }
    fscanf(fin,"%d",&nr);
    int matrice[nr][100];
    int matriceordinata[nr][100];

    for(i=0;i<nr;i++){
        fscanf(fin,"%d",&nc);
        for (j=0;j<nc;j++) {
            fscanf(fin,"%d",&matrice[i][j]);
            matriceordinata[i][j]=matrice[i][j];
        }
    }

    for(i=0;i<nr;i++){
        printf("\n\n");
        printf("InsertionSort\n");
        InsertionSort(matrice[i], nc);

        riempi(matrice[i],matriceordinata[i],nc);

        printf("\n\n");
        printf("SelectionSort\n");
        SelectionSort(matrice[i],nc);

        riempi(matrice[i],matriceordinata[i],nc);

        printf("\n\n");
        printf("ShellSort\n");
        ShellSort(matrice[i],nc);

        riempi(matrice[i],matriceordinata[i],nc);
        }


}
