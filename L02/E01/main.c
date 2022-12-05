#include <stdio.h>

int main() {
    int num1, num2;
    printf("digita i due numeri per trovate il MCD\n");
    scanf("%d %d",&num1,&num2);

    while(num1!=0 && num2!=0){
        if (num1>num2){
            num1=num1%num2;
        }
        else{
            num2=num2%num1;
        }
    }

    if (num1!=0){
        printf("Il MCD e' %d",num1);
    }

    else{
        printf("Il MCD e' %d",num2);
    }





}
