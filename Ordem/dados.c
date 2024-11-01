#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int Idade;
    int Peso;
} Dados;

//Funções

void swap(Dados **A, Dados **B);
void quicksort(Dados **V, int inf, int sup);
int particao(Dados **V, int inf, int sup);
int comparar(Dados **A, Dados **B);

//Função principal

int main(){
    system("cls");
    Dados D1 = {25, 50};
    Dados D2 = {20, 30};
    Dados D3 = {30, 40};
    Dados D4 = {20, 65};
    Dados D5 = {20, 40};
    Dados D6 = {18, 60};
    Dados D7 = {30, 45};
    Dados D8 = {18, 65};
    Dados D9 = {41, 90};

    Dados *Vetor[] = {&D1, &D2, &D3, &D4, &D5, &D6, &D7, &D8, &D9};
    int N = sizeof(Vetor)/sizeof(Vetor[0]);

    quicksort(Vetor, 0, N - 1);

    printf("Dados ordenados: \n");
    for (int i = 0; i < N; i++) printf("{%d,%d} ", Vetor[i]->Idade, Vetor[i]->Peso);
    printf("\n");

    return 0;
}

//Implementação de funções

void swap(Dados **A, Dados **B){
    Dados *temp = *A;
    *A = *B;
    *B = temp;
}

int particao(Dados **V, int inf, int sup){
    Dados *Pivot = V[(inf + sup)/2];
    int i = inf;
    int j = sup;
    while(i <= j){
        while (comparar(&V[i], &Pivot) < 0) i++;
        while (comparar(&V[j], &Pivot) > 0) j--;
        if (i <= j){
            swap(&V[i], &V[j]);
            i++;
            j--;
        }
    }
    return (i);
}

void quicksort(Dados **V, int inf, int sup){
    if ( inf < sup){
        int P = particao(V, inf, sup);
        quicksort(V, inf, P-1);
        quicksort(V, P, sup);
    }
}

int comparar(Dados **A, Dados **B){
    Dados *X = *A;
    Dados *Y = *B;

    int DeltaIdade = X->Idade - Y->Idade;
    int DeltaPeso = X->Peso - Y->Peso;

    if(X->Idade != Y->Idade)return DeltaIdade;
    else return DeltaPeso;
}