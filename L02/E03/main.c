#include <stdio.h>

int comprimi(FILE *fin,FILE *fout) {
    char ch1, ch2,flag='f';
    int conta=0,i,conta2=1;
    fscanf(fin,"%c",&ch1);
    fprintf(fout,"%c",ch1);

    while(fscanf(fin,"%c",&ch2)!=EOF){

        if (flag=='t' && ch2==ch1){
            flag='f';
        }

        if(ch2==ch1){
            conta++;

            while(flag=='f'&& fscanf(fin,"%c",&ch2)!=EOF){

                if (ch2==ch1){
                    conta++;
                }
                else{
                    flag='t';
                }

            }


            if(conta==1){
                fprintf(fout,"%c%c",ch1,ch2);
                conta2=conta2+2;
            }

            else if(conta<=9){
                if (ch1!=ch2){
                    fprintf(fout,"$%d%c",conta,ch2);
                    conta2=conta2+3;
                }
                else{
                    fprintf(fout,"$%d",conta);
                    conta2=conta2+2;
                }

            }


            else{
                for(i=0;i<conta/9;i++){
                    fprintf(fout,"$9%c",ch1);
                    conta2=conta2+3;
                }
                if(conta/i%9==1) {
                    fprintf(fout, "%c", ch2);
                    conta2++;
                }
                else if(conta/i%9<3){
                    fprintf(fout,"%c%c",ch1,ch2);
                    conta2=conta2+2;
                }
                else{
                    fprintf(fout,"$%d%c",conta%9-i,ch2);
                    conta2=conta2+3;
                }

            }

        }

        else{
            fprintf(fout,"%c",ch2);
            conta2++;
            flag='f';
        }


        ch1=ch2;
        conta=0;

    }

    return conta2;
}


int decomprimi(FILE *fin,FILE *fout){
    char ch1, ch2;
    int i,conta=0;
    fscanf(fin,"%c",&ch1);
    fprintf(fout,"%c",ch1);
    conta++;
    while(fscanf(fin,"%c",&ch2)!=EOF){
        if(ch2=='$'){
            fscanf(fin,"%c",&ch2);
            for(i=0;i<ch2-'0';i++){
            fprintf(fout,"%c",ch1);
            conta++;
            }
        }

        else{
            fprintf(fout,"%c",ch2);
            conta++;
        }

        ch1=ch2;
    }
    return conta;

}



int main(){
    int scelta, x,y;
    FILE *fin,*fout1;
    printf("Inserire:\n1 comprimi\n2 decomprimi\n");
    scanf("%d", &scelta);
    switch(scelta){
        case 1:
            if((fin = fopen("sorgente.txt", "r"))==NULL){
                printf("Errore apertura file\n");
                return 0;
            }
            if((fout1 = fopen("compresso.txt", "w"))==NULL){
                printf("Errore apertura file\n");
                return 1;
            }
            x=comprimi(fin,fout1);
            printf("%d",x);
            break;


        case 2:
            if((fin = fopen("compresso.txt", "r"))==NULL){
                printf("Errore apertura file\n");
                return 0;
            }
            if((fout1 = fopen("de-compresso.txt", "w"))==NULL){
                printf("Errore apertura file\n");
                return 1;
            }

            y=decomprimi (fin,fout1);
            printf("%d",y);
            break;
    }
}