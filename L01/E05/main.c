#include <stdio.h>

int main() {
    char operazione;
    float op1, op2, calcolo;
    printf("digita operazione\n");
    operazione=getchar();
    printf("digita i due operandi\n");
    scanf("%f %f",&op1,&op2);

    switch (operazione) {
        case '+':
            calcolo=op1+op2;
            printf("%f %c %f=%f",op1,operazione,op2,calcolo);
            break;
        case '-':
            calcolo=op1-op2;
            printf("%f %c %f=%f",op1,operazione,op2,calcolo);
            break;

        case '*':
            calcolo=op1*op2;
            printf("%f %c %f=%f",op1,operazione,op2,calcolo);
            break;

        case '/':
            if (op2!=0){
                calcolo=op1/op2;
                printf("%f %c %f=%f",op1,operazione,op2,calcolo);
            }
            else{
                printf("errore");
                return 1;
            }

            break;

            default:
                printf("errore di input");
            break;

                }



}
