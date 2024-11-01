#include <stdio.h>
#include <stdlib.h>

//Funções

void swap(int *A, int *B);
void Quicksort(int V[], int inf, int sup);
int particao(int V[], int inf, int sup);

//Função principal

int main(){
    system("cls");

    int arr[20] = {25, 17, 31, 13, 2, 19, 8, 14, 7, 1, 22, 10, 3, 12, 9, 5, 6, 16, 11, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Vetor desordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    Quicksort(arr, 0, n - 1);

    printf("\nVetor ordenado:\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

//Implementação de funções

void swap(int *A, int *B){
    int temp = *A;
    *A = *B;
    *B = temp;
}

int particao(int V[], int inf, int sup){
    int Pivot = V[(inf + sup)/2];
    int i = inf;
    int j = sup;
    while(i <= j){
        while(V[i] < Pivot) i++; //percorrendo o vetor a partir da esquerda
        while(V[j] > Pivot) j--; //percorrendo o vetor a partir da direita
        if (i <= j){
            swap(&V[i], &V[j]);
            i++;
            j--;
        }
    }
    return (i);
}

void Quicksort(int V[], int inf, int sup){
    if ( inf < sup){
        int P = particao(V, inf, sup);
        Quicksort(V, inf, P-1);
        Quicksort(V, P, sup);
    }
}