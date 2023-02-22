long int fib_seq[81] = {0};

long int fibonacci (int n){
    fib_seq[1] = 1;
    fib_seq[2] = 1;
    if(fib_seq[n] != 0){
        return fib_seq[n];
    }

    fib_seq[n] = fibonacci(n-1)+fibonacci(n-2);
    return fib_seq[n];
}