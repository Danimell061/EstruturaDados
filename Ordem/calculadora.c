#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // Para isdigit

#define SIM 1
#define NAO 0

typedef struct Item {
    double Chave;
    struct Item *Anterior;
} Item;

typedef struct {
    int Tamanho;
    Item *Topo; // FIM
} Pilha;

Pilha *inicializar() {
    Pilha *P = (Pilha *)malloc(sizeof(Pilha));

    if (P == NULL) {
        printf("ERRO: Não foi possivel alocar a memoria!");
        exit(1);
    }

    P->Topo = NULL;
    P->Tamanho = 0;

    return P;
}

int Vazio(Pilha *P) {
    return (P->Tamanho == 0) ? SIM : NAO;
}

void empilhar(Pilha *P, Item *I) {
    I->Anterior = P->Topo;
    P->Topo = I;
    P->Tamanho++;
}

Item *desempilhar(Pilha *P) {
    if (Vazio(P)) {
        printf("ERRO: A pilha esta vazia!\n");
        return NULL;
    }

    Item *I = P->Topo;
    P->Topo = I->Anterior;
    P->Tamanho--;

    return I;
}

Item *criarItem(double C) {
    Item *E = (Item *)malloc(sizeof(Item));

    if (E == NULL) {
        printf("ERRO: Problema em alocar memoria;");
        exit(1);
    }
    E->Chave = C;
    E->Anterior = NULL;

    return E;
}

// Avaliar

double avaliar(const char *Expressao) {
    Pilha *P = inicializar();

    for (int i = 0; Expressao[i] != '\0'; i++) {
        if (isdigit(Expressao[i])) {
            Item *I = criarItem((double)(Expressao[i] - '0'));
            empilhar(P, I);
        } else if (Expressao[i] == ' ' || Expressao[i] == '\t') {
            continue;
        } else {
            Item *I2 = desempilhar(P);
            Item *I1 = desempilhar(P);

            if (I1 == NULL || I2 == NULL) {
                printf("ERRO: Pilha inconsistente!\n");
                exit(EXIT_FAILURE);
            }

            double Operando2 = I2->Chave;
            double Operando1 = I1->Chave;
            double Res;
            Item *I;

            switch (Expressao[i]) {
                case '+':
                    Res = Operando1 + Operando2;
                    break;
                case '-':
                    Res = Operando1 - Operando2;
                    break;
                case '*':
                    Res = Operando1 * Operando2;
                    break;
                case '/':
                    if (Operando2 == 0) {
                        printf("ERRO: Divisão por zero!\n");
                        exit(EXIT_FAILURE);
                    }
                    Res = Operando1 / Operando2;
                    break;
                default:
                    printf("ERRO: operador invalido!\n");
                    exit(EXIT_FAILURE);
            }

            I = criarItem(Res);
            empilhar(P, I);
            free(I1); // Liberar memória dos itens desempilhados
            free(I2);
        }
    }

    Item *resultadoItem = desempilhar(P);
    double resultado = resultadoItem->Chave;
    free(resultadoItem); // Liberar a memória do resultado
    free(P); // Liberar a memória da pilha

    return resultado;
}

int main(void) {
    const char *Expressao = "2 4 + 5 *";
    double resultado = avaliar(Expressao);
    printf("Resultado: %f \n", resultado);

    return 0;
}
