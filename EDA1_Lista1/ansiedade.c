#include <stdio.h>
#include <string.h>

int main(){
    int n_triagens, n_sims, cont;
    char res[3];
    n_triagens = 0;
    cont = 1;
    while(scanf("%s", res) != EOF){
        if(strcmp(res, "sim") == 0){
            n_sims++;
        }
        if(cont == 10){
            if(n_sims >= 2){
                n_triagens++;
            }
            n_sims = 0;
            cont = 0;
        }
        cont++;
    }
    printf("%d", n_triagens);
}
