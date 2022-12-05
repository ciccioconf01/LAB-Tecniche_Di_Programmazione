#include <stdio.h>
#include<string.h>
typedef struct {
    char codice[30];
    char partenza[30];
    char arrivo[30];
    char data[30];
    char ora_partenza[30];
    char ora_arrivo[30];
    int ritardo;
}dizionario;

typedef enum {
    r_date, r_partenza, r_capolinea, r_ritardo, r_ritardo_tot, r_fine,
}comando_e;

comando_e leggiComando(){
    comando_e x;
    char stringa[30];
    char tabella[r_fine][15]={
        "data","partenza","capolinea","ritardo","ritardo_totale"
    };
    printf("interrogazione per (data/partenza/capolinea/ritardo/ritardo_totale/fine)\n");
    scanf("%s",stringa);
    x=r_date;
    while (x<r_fine && strcmp(stringa,tabella[x])){
        x++;
    }
    return x;
}

void date(dizionario diz[],int n){
    int conta = 0;
    char data1[40], data2[40];
    printf("Inserire la data di inizio della verifica nel formato aaaa/mm/gg:\n");
    scanf("%s",data1);
    printf("Inserire la data di fine della verifica nel formato aaaa/mm/gg:\n");
    scanf("%s",data2);
    for(int i = 0;i<n;i++){
        if(strcmp(data1,diz[i].data)<=0){
            if(strcmp(diz[i].data,data2)<=0){
                conta++;
                if(conta == 1){
                    printf("La lista delle corse da %s a %s:\n",data1,data2);
                }
                printf("%s %s %s %s %s %s",diz[i].codice,diz[i].partenza,diz[i].arrivo,diz[i].data,diz[i].ora_partenza,diz[i].ora_arrivo);
                printf("\n");
            }
        }
    }
    if(conta == 0){
        printf("Nessun risultato");
    }
}

void partenza(dizionario diz[], int n){
    char richiesta[30];
    printf("Inserire la partenza:\n");
    scanf("%s",richiesta);
    for (int i=0;i<n;i++){
        if(strcmp(diz[i].partenza,richiesta)==0){
            printf("%s %s %s %s %s %s\n",diz[i].codice,diz[i].partenza,diz[i].arrivo,diz[i].data,diz[i].ora_partenza,diz[i].ora_arrivo);
        }
    }
}

void capolinea(dizionario diz[], int n){
    char richiesta[30];
    printf("Inserire il capolinea:\n");
    scanf("%s",richiesta);
    for (int i=0;i<n;i++){
        if(strcmp(diz[i].arrivo,richiesta)==0){
            printf("%s %s %s %s %s %s\n",diz[i].codice,diz[i].partenza,diz[i].arrivo,diz[i].data,diz[i].ora_partenza,diz[i].ora_arrivo);
        }
    }
}
void ritardo_tot(dizionario diz[], int n){
    char richiesta[30];
    int somma = 0;
    printf("Inserire il codice della tratta:\n");
    scanf("%s",richiesta);
    for (int i=0;i<n;i++){
        if(strcmp(diz[i].codice,richiesta)==0){
            somma = somma + diz[i].ritardo;
        }
    }
    printf("Il ritardo totale accumulato nella tratta con codice %s e' di %d minuti\n",richiesta,somma);
}

void ritardo(dizionario diz[], int n){
    int conta = 0;
    char data1[40], data2[40];
    printf("Inserire la data di inizio della verifica nel formato aaaa/mm/gg:\n");
    scanf("%s",data1);
    printf("Inserire la data di fine della verifica nel formato aaaa/mm/gg:\n");
    scanf("%s",data2);
    for(int i = 0;i<n;i++){
        if(strcmp(data1,diz[i].data)<=0){
            if(strcmp(diz[i].data,data2)<=0){
                if (diz[i].ritardo>0){
                    conta++;
                    if(conta == 1){
                        printf("La lista delle corse in ritardo da %s a %s:\n",data1,data2);
                    }
                    printf("%s %s %s %s %s %s",diz[i].codice,diz[i].partenza,diz[i].arrivo,diz[i].data,diz[i].ora_partenza,diz[i].ora_arrivo);
                    printf("\n");
                }
            }
        }
    }
    if(conta == 0){
        printf("Nessun ritardo trovato\n");
    }
}

void menuParola(dizionario diz[],int n,comando_e comando){
    int continua=1;
    while (continua){
        comando=leggiComando();

        switch (comando) {
        case r_date:
            date(diz,n);
            break;
        case r_partenza:
            partenza(diz,n);
            break;
        case r_capolinea:
            capolinea(diz,n);
            break;
        case r_ritardo:
            ritardo(diz,n);
            break;
        case r_ritardo_tot:
            ritardo_tot(diz,n);
        case r_fine:
            continua=0;
            break;
    }
    }
}


int main() {
    FILE *fin;
    dizionario diz[1000];
    comando_e comando;
    int n,i;
    if((fin=fopen("log.txt","r"))==NULL){
        printf("errore di apertura");
        return 1;
    }
    fscanf(fin,"%d",&n);
    if(n>1000){
        printf("file non valido");
        return 2;
    }

    for(i=0;i<n;i++){
        fscanf(fin,"%s",diz[i].codice);
        fscanf(fin,"%s",diz[i].partenza);
        fscanf(fin,"%s",diz[i].arrivo);
        fscanf(fin,"%s",diz[i].data);
        fscanf(fin,"%s",diz[i].ora_partenza);
        fscanf(fin,"%s",diz[i].ora_arrivo);
        fscanf(fin,"%d",&diz[i].ritardo);
    }

    menuParola(diz,n,comando);
}
