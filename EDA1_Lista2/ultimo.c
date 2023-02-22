#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int x, valido, n_letras;
    unsigned int msg;
    char linha[8];
    char *letras;
    valido = 1;
    letras = (char*)malloc(4*sizeof(char));
    n_letras = 0;
    while(valido == 1){
        if(scanf("%x%n", &msg, &x) != EOF){
            strcpy(linha, (char*)&msg);
            n_letras += (x/2);
            letras = (char*)realloc(letras, n_letras*sizeof(char));
            if(x/2 != 4){
                valido = 0;
            }
            for(int i = 0; i<(x/2); i++){
                letras[n_letras - (x/2) + i] = linha[i];
            }          
        } else{
            valido = 0;
        }
    }
    for(int i = 0; i<n_letras; i++){
        printf("%c", letras[i]);
    }    
    printf("\n");
}