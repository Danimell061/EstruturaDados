#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cidades.h"

int main () {
    int Soma = 0;
    int NumTeste = 0;
    FILE *Resposta = fopen("Resultado.txt", "w");
    Estrada *T1 = getEstrada("Teste01.txt");
    double D1 = calcularMenorVizinhanca("Teste01.txt");
    char *C1 = cidadeMenorVizinhanca("Teste01.txt");

    printf("%d\n", T1->T);
    if (T1->T == 20) Soma++;
    NumTeste++;
    printf("%d\n", T1->N);
    if (T1->N == 6) Soma++;
    NumTeste++;
    printf("%.1f\n", D1);
    if (D1 == 2) Soma++;
    NumTeste++;
    printf("%s\n", C1);
    if (strcmp(C1, "Kikozinho Lindo")==0){
        Soma++;
    } 
    NumTeste++;
    fprintf(Resposta, "\n\nATENÇÃO: Você acertou %d de %d itens. Logo, em 2.00 pontos, sua nota foi %.2f.\n", Soma, NumTeste, 2.0 * (float)Soma/(float)NumTeste);
}