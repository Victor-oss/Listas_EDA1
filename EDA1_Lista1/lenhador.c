#include <stdio.h>
#include <stdlib.h>

int main(){
    int n_linhas, L, G, *linha_g, col_len, linha_real, morreu, referencial, cont, pular;
    char *lado_g, **arvore;
    char lado_lenhador, cods[2000];
    scanf("%d", &L);
    scanf("%d", &G);
    lado_g = (char*)malloc(G*sizeof(char));
    linha_g = (int*)malloc(G*sizeof(int));
    for(int i = 0; i < G; i++) {
        getchar();
        scanf("%c %d", &lado_g[i], &linha_g[i]);
    }
    getchar();
    scanf("%c", &lado_lenhador);
    if(lado_lenhador == 'D'){
        col_len = 8;
    } else {
        col_len = 2;
    }
    getchar();
    fgets(cods, 2000, stdin);
    arvore = (char**)malloc((L+7)*sizeof(char*));
    for(int a = 0; a < L+7; a++){
        arvore[a] = (char*)malloc(11*sizeof(char));
        if(a == 0 || a == L+6){
            for(int b = 0; b < 11; b++){
                arvore[a][b] = '~';
            }
        } else {
            for(int b = 0; b < 11; b++){
                if(a > 5){
                    if(b >= 4 && b <= 6){
                        arvore[a][b] = '|';
                    } else {
                        if((a == L+5 || a == L+4) && b == col_len){
                            arvore[a][b] = 'L';
                        } else {
                            arvore[a][b] = ' ';
                        }
                    }
                } else {
                    arvore[a][b] = ' ';
                }    
            }
        }
    } 

    for(int i = 0; i<G; i++){
        linha_real = L + 6 - linha_g[i];
        if(lado_g[i] == 'D'){
            for(int j = 8; j < 11; j++){
                arvore[linha_real][j] = '-';
            }
        }else if(lado_g[i] == 'E'){
            for(int j = 1; j < 4; j++){
                arvore[linha_real][j] = '-';
            }
        }
    }

    referencial = L+1; 
    morreu = 0;
    cont = 0;
    pular = 0;
    for(int j = 0; j < 11; j++){
        printf("%c", arvore[0][j]);           
    }
    printf("\n");
    for(int i = referencial; i<(referencial+5); i++){
        for(int j = 0; j < 11; j++){
            printf("%c", arvore[i][j]);           
        }
        printf("\n");
    }
    for(int j = 0; j < 11; j++){
        printf("%c", arvore[L+6][j]);           
    } 
    printf("\n");
    while(morreu == 0 && cods[cont] != '\n'){
        if(cods[cont] == 'T'){
            if(col_len == 8){
                if(arvore[referencial+3][2] == '-' || arvore[referencial+4][2] == '-'){
                    pular = 1;
                    printf("**beep**\n");
                } else {
                    col_len = 2;
                    arvore[referencial+3][col_len] = 'L';
                    arvore[referencial+4][col_len] = 'L';
                    arvore[referencial+3][8] = ' ';
                    arvore[referencial+4][8] = ' ';
                }
            } else {
                if(arvore[referencial+3][8] == '-' || arvore[referencial+4][8] == '-'){
                    pular = 1;
                    printf("**beep**\n");
                } else {
                    col_len = 8;
                    arvore[referencial+3][col_len] = 'L';
                    arvore[referencial+4][col_len] = 'L';
                    arvore[referencial+3][2] = ' ';
                    arvore[referencial+4][2] = ' ';
                }
            }
        } else if (cods[cont] == 'B'){
            if(col_len == 8){
                if(arvore[referencial+4][6] == '<'){
                    if(arvore[referencial+2][8] == '-'){
                        morreu = 1;
                        pular = 1;
                        printf("**morreu**\n");
                    } else {
                        arvore[referencial+2][8] = 'L';
                        referencial--;
                    }
                } else {
                    arvore[referencial+4][6] = '<';
                }   
            } else {
                if(arvore[referencial+4][4] == '>'){
                    if(arvore[referencial+2][2] == '-'){
                        morreu = 1;
                        pular = 1;
                        printf("**morreu**\n");
                    } else {
                        arvore[referencial+2][2] = 'L';
                        referencial--;
                    }
                } else {
                    arvore[referencial+4][4] = '>';
                } 
            }
        }

        if(pular == 0){
            for(int j = 0; j < 11; j++){
                printf("%c", arvore[0][j]);           
            }
            printf("\n");
            for(int i = referencial; i<(referencial+5); i++){
                for(int j = 0; j < 11; j++){
                    printf("%c", arvore[i][j]);           
                }
                printf("\n");
            }
            for(int j = 0; j < 11; j++){
                printf("%c", arvore[L+6][j]);           
            } 
            printf("\n");
        }
        pular = 0;
        cont++;
    } 
}