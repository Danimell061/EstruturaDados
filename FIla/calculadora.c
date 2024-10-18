#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // Para isdigit
#include <math.h>

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
            double Operando1;
            double Operando2;
            double Res;

            Item *I;

            switch (Expressao[i]) {
                case '+':
                    Operando2 = desempilhar(P)->Chave;
                    Operando1 = desempilhar(P)->Chave;
                    Res = Operando1 + Operando2;
                    break;
                case '-':
                    Operando2 = desempilhar(P)->Chave;
                    Operando1 = desempilhar(P)->Chave;
                    Res = Operando1 - Operando2;
                    break;
                case '*':
                    Operando2 = desempilhar(P)->Chave;
                    Operando1 = desempilhar(P)->Chave;
                    Res = Operando1 * Operando2;
                    break;
                case '/':
                    Operando2 = desempilhar(P)->Chave;
                    Operando1 = desempilhar(P)->Chave;

                    if (Operando2 == 0) {
                        printf("ERRO: Divisão por zero!\n");
                        exit(EXIT_FAILURE);
                    }
                    Res = Operando1 / Operando2;
                    break;

                case 'l':
                    Operando1 = desempilhar(P)->Chave;

                    if (Expressao[i+1] != 'o' || Expressao[i+2] != 'g') {
                        printf("ERRO: Problema na expressao com LOG");
                        exit(EXIT_FAILURE);
                    }
                    else {
                        Res = log10(Operando1);
                    }
                    break;

                case 'o':
                    if (Expressao[i - 1] != 'l' || Expressao[i + 1] != 'g') {
                        printf("ERRO: Problema na expressao com LOG");
                        exit(EXIT_FAILURE);
                    }
                    break;

                case 'g':
                    if (Expressao[i - 2] != 'l' || Expressao[i - 1] != 'o') {
                        printf("ERRO: Problema na expressao com LOG");
                        exit(EXIT_FAILURE);
                    }
                    break;

                default:
                    printf("ERRO: operador invalido!\n");
                    exit(EXIT_FAILURE);
            }

            I = criarItem(Res);
            empilhar(P, I);
        }
    }

    Item *resultadoItem = desempilhar(P);
    double resultado = resultadoItem->Chave;
    free(resultadoItem); // Liberar a memória do resultado
    free(P); // Liberar a memória da pilha

    return resultado;
}

int main(void) {
    const char *Expressao = "2 log";
    double resultado = avaliar(Expressao);
    printf("Resultado: %.3f \n", resultado);

    return 0;
}
