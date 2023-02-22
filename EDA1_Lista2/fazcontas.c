int faz_conta_direito(int parcelas, char op){
    int *vals, total;
    vals = (int*)malloc(parcelas*sizeof(int));
    if(op == '+'){
        total = 0;
        for(int i = 0; i<(parcelas-1);i++){
            scanf("%d ", &vals[i]);
            total += vals[i];
        }
        scanf("%d", &vals[parcelas-1]);
        total += vals[parcelas-1];
    } else {
        scanf("%d", &vals[0]);
        total = vals[0];
        for(int i = 1; i<parcelas;i++){
            scanf(" %d ", &vals[i]);
            total -= vals[i];
        }
    }
    return total;
}
