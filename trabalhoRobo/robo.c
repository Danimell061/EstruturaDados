#include <stdio.h>
#include <stdlib.h>
#include "robo.h"

Caminho *iniciarCaminho(int N) {
    Caminho *caminho = (Caminho *)malloc(sizeof(Caminho));

    caminho->Origem = (Ponto *)malloc(sizeof(Ponto));
    caminho->Origem->X = 0;
    caminho->Origem->Y = 0;
    caminho->Origem->Proximo = NULL;
   
    caminho->N = N;
    caminho->Distancia = 0;
   
    return caminho;
}

Ponto Final(Caminho *C) {
    Ponto final = {0, 0};
   
    if (C->N <= 0) {
        return final;
    }
   
    int x = 0;
    int y = 0;
    int direcao = 0;
    int passo = 1;

    for (int i = 0; i < C->N; i++) {
        switch (direcao) {
            case 0:
            x += passo;

            break;

            case 1:
            y += passo;

            break;

            case 2:
            x -= passo;

            break;  

            case 3:
            y -= passo;
           
            break;
        }

        //90°
        direcao = (direcao + 1) % 4;
       
        if (i % 2 == 1) {
            passo++;
        }
    }

    final.X = x;
    final.Y = y;
   
    return final;
}

int Distancia(Caminho *C) {
    int distanciaTotal = 0;
    int passo = 1;
   
    if (C->N <= 0) {
        return 0;
    }
   
    for (int i = 0; i < C->N; i++) {
        distanciaTotal += passo;
       
        if (i % 2 == 1) {
            passo++;
        }
    }

    return distanciaTotal;
}