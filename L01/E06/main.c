#include <stdio.h>

int main() {
    FILE *file1,*file2;
    char operazione;
    float op1, op2, calcolo;
    if((file1 = fopen("Operazioni.txt", "r"))==NULL){
        printf("Errore apertura file\n");
        return 0;
    }
    if((file2 = fopen("Results.txt", "w"))==NULL){
        printf("Errore apertura file\n");
        return 1;
    }
    do
        {

        fscanf(file1,"%c %f %f\n",&operazione,&op1,&op2);

        switch (operazione) {
            case '+':
                calcolo=op1+op2;
                fprintf(file2,"%.2f %c %.2f=%.2f\n",op1,operazione,op2,calcolo);
                break;
            case '-':
                calcolo=op1-op2;
                fprintf(file2,"%.2f %c %.2f=%.2f\n",op1,operazione,op2,calcolo);
                break;

            case '*':
                calcolo=op1*op2;
                fprintf(file2,"%.2f %c %.2f=%.2f\n",op1,operazione,op2,calcolo);
                break;

            case '/':
                if (op2!=0){
                    calcolo=op1/op2;
                    fprintf(file2,"%.2f %c %.2f=%.2f\n",op1,operazione,op2,calcolo);
                }
                else{
                    printf("errore");
                    return 2;
                }

                break;

            default:
                printf("errore");

        }
    } while (!feof(file1));

}