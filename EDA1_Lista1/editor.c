#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char **texto, comando, exemplo[1000];
    int n_linhas, tam, linha, coluna, col_auxiliar, c_fim, *tam_linhas;
    scanf("%d", &n_linhas);
    texto = (char**)malloc(n_linhas*sizeof(char*));
    getchar();
    tam_linhas = (int*)malloc(n_linhas*sizeof(int));
    for(int i = 0; i < n_linhas; i++){
        fgets(exemplo, 1000, stdin);
        tam = strlen(exemplo);
        tam_linhas[i] = tam - 1;
        texto[i] = (char*)malloc(tam*sizeof(char));  
        for(int b = 0; b < tam; b++){
            texto[i][b] = exemplo[b];  
        }
    }
    scanf("%d %d", &linha, &coluna);
    fflush(stdin);
    while(scanf("%c", &comando) != EOF){
        if(comando == 'j'){
            if(linha < n_linhas){
                linha = linha + 1;
            }
            if(coluna <= tam_linhas[linha - 1]){
                printf("%d %d %c\n", linha, coluna, texto[linha-1][coluna-1]);
            } else {
                printf("%d %d %c\n", linha, tam_linhas[linha - 1], texto[linha-1][tam_linhas[linha - 1]-1]);
            }
        } else if(comando == 'k'){
            if(linha > 1){
                linha = linha - 1;
            }
            if(coluna <= tam_linhas[linha - 1]){
                printf("%d %d %c\n", linha, coluna, texto[linha-1][coluna-1]);
            } else {
                printf("%d %d %c\n", linha, tam_linhas[linha - 1], texto[linha-1][tam_linhas[linha - 1]-1]);
            }
        }
    }
    return 0;
}