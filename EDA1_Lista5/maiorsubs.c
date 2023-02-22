#include <stdio.h>

char qtd_subs, sub[101], cont_subs, cont, pode_contar;
int tam_subs;

char eigualsub(char *v1, char *sub){
    if(*(sub) == '\0') return 1;
    if(*v1 == *sub) return eigualsub(v1+1, sub+1);
    return -1; 
}

char numsubs(char *vetor, char *sub){
    if(*vetor == '\0') return 0;
    if(eigualsub(vetor, sub) == 1) return numsubs(vetor+1, sub)+1;
    return numsubs(vetor+1, sub);
}

char tamanho_maior_sub(
    char *str, 
    char *sub){
    int resultado = eigualsub(str, sub);

    if(resultado == 1 && cont_subs < qtd_subs-1){
        pode_contar = 1;
        cont_subs++;
        cont++;
        return tamanho_maior_sub(str+1, sub);
    } 

    if(resultado == 1 && cont_subs == qtd_subs-1){
        return cont + tam_subs;
    } 

    if(pode_contar == 1){
        cont++;
        return tamanho_maior_sub(str+1, sub);
    } 

    if(cont_subs == 0){
        return tamanho_maior_sub(str+1, sub);
    } 
}

int main(){
    char str[101], tamstr, tamaior = 0;
    pode_contar = 0;
    cont_subs = 0;
    cont = 0;
    scanf("%[^\n]s", str);
    getchar();
    scanf("%s%n", sub, &tam_subs);
    qtd_subs = numsubs(str, sub);
    if(qtd_subs > 1){
        tamaior = tamanho_maior_sub(str, sub);
        printf("%d\n", tamaior);
    } else if(qtd_subs == 1){
        printf("%hhd\n", tam_subs);
    } else {
        printf("%d\n", tamaior);
    }
}