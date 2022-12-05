#include <stdio.h>
#define filein "input.txt"
#define fileout "testo.txt"


int main() {
    FILE *fin,*fout;
    char carattere,flag='f',flag2='f',flag3='f',flag4='f';
    int i,n=0,conta=0;
    if((fin=fopen(filein,"r"))==NULL){
        printf("errore di apertura");
        return 0;
    }
    if((fout=fopen(fileout,"w"))==NULL){
        printf("errore di apertura");
        return 1;
    }

    while (fscanf(fin,"%c",&carattere)!=EOF){
        n++;


        if(flag=='t') {
            if (carattere != ' ' && carattere != '\n') {
                fprintf(fout, " ");
                n++;
                conta++;

            }
            if (carattere=='\n'){
                for(i=0;i<=25-n;i++){
                    fprintf(fout," ");

                }
                fprintf(fout,"|c:%d\n",n);
                n=0;

                fscanf(fin,"%c",&carattere);
                n++;
                flag3='t';

            }
            flag = 'f';
        }

            if (flag2 == 't') {
                if (carattere >= 97 && carattere <= 122) {
                    carattere = carattere - ' ';
                    fprintf(fout, "%c", carattere);
                } else {
                    fprintf(fout, "%c", carattere);
                }
                flag2 = 'f';
                flag4='t';
            }

            if(carattere=='\n'&&flag3!='t'){
                for(i=0;i<=25-n;i++){
                    fprintf(fout," ");

                }
                fprintf(fout,"|c:%d\n",n-conta);
                n=0;
                conta=0;

            }

        else if (carattere>=48 && carattere<=57){
            fprintf(fout,"*");
        }

        else if (carattere=='.'||carattere==','||carattere==';'||carattere==':'||carattere=='!'||carattere=='?'||carattere=='('){
            flag='t';
            fprintf(fout,"%c",carattere);
            if (carattere=='!'||carattere=='?'||carattere=='.'){
                flag2='t';
            }
        }

        else if (flag3!='t'&&flag4!='t'){
            fprintf(fout,"%c",carattere);
        }

        if (n>=25){
            fprintf(fout,"|c:%d\n",n-conta);
            conta=0;
            n=0;
        }
        flag3='f';
        flag4='f';


    }
}

