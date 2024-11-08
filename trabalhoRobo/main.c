#include <stdio.h>
#include <stdlib.h>
#include "robo.h"

int main(){
    Caminho *c1 = iniciarCaminho(-4);
    Ponto final = Final(c1);

    printf("Posição final: X = %d, Y = %d\n", final.X, final.Y);
    printf("Distância: %d", Distancia(c1));
    // printf("Distância total percorrida: %d\n", Distancia(c1));
    
    // Liberar memória
    free(c1->Origem);
    free(c1);

    return 0;
}