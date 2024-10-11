#include <stdio.h>
#include <stdlib.h>

int Fat(int N);

int main(void){
    printf("\nO fatorial de 4 e %d.\n", Fat(4));
    return 0;
}

int Fat(int N){
    int R;

    printf("1 %d\n", &R);

    if (N == 0 || N == 1) R = 1;
    else R = N * Fat(N - 1);

    printf("2 %d\n", &R);

    return R;
}