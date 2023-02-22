#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int x, valido, n_letras, a, b;
    unsigned int msg;
    char linha[8];
    short int *letras;
    valido = 1;
    letras = (short int*)malloc(4*sizeof(short int));
    n_letras = 0;
    while(valido == 1){
        if(scanf("%x%n", &msg, &x) != EOF){
            getchar();
            strcpy(linha, (char*)&msg);
            n_letras += (x/2);
            letras = (short int*)realloc(letras, n_letras*sizeof(short int));
            printf("%d\n", x);
            if(x == 8){
                for(int i = 7; i>0; i-= 2){
                    if(linha[i] >= 'a' && linha[i] <= 'f'){
                        switch(linha[i]){
                            case 'a':
                                a = 10;
                            break;
                            case 'b':
                                a = 11;
                            break;
                            case 'c':
                                a = 12;
                            break;
                            case 'd':
                                a = 13;
                            break;
                            case 'e':
                                a = 14;
                            break;
                            default:
                                a = 15;
                                break;
                        }
                    } else {
                        a = linha[i] - '0';
                    }
                    b = (linha[i-1] - '0')*16;
                    letras[n_letras + (((7 - i)/2) - 4)] = b+a;
                }
            } else {
                x = x%2 == 0 ? x : x-1; 
                for(int i = x-1; i>0; i-= 2){
                    if(linha[i] >= 'a' && linha[i] <= 'f'){
                        switch(linha[i]){
                            case 'a':
                                a = 10;
                            break;
                            case 'b':
                                a = 11;
                            break;
                            case 'c':
                                a = 12;
                            break;
                            case 'd':
                                a = 13;
                            break;
                            case 'e':
                                a = 14;
                            break;
                            default:
                                a = 15;
                                break;
                        }
                    } else {
                        a = linha[i] - '0';
                    }
                    b = (linha[i-1] - '0')*16;
                    letras[n_letras + (((x - i)/2) - (x/2))] = b+a;
                }
                printf("\n%d\n", valido);
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