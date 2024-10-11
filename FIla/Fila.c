#include <stdio.h>
#include <stdlib.h>

#define NAO 0
#define SIM 1

typedef struct Item{
    int Chave;
    struct Item *Proximo;
} Item;

typedef struct{
    Item *Inicio;
    Item *Final;
    int Tamanho;
} Fila;

Fila *criarFila();
int filaVazia(Fila *F);
void enfilerar(Fila *F, Item *I);
void exibirFila(Fila *F);
Item *criarItem(int C);
Item *posicaoFila(Fila *F, int N);
Item *desenfileirar(Fila *F);

Fila *criarFila(){
    Fila *F = (Fila *)malloc(sizeof(Fila));
    if ( F == NULL){
        printf("ERRO: Problema em alocar memoria;");
        exit(1);
    }
    F->Inicio;
    F->Final;
    F->Tamanho = 0;

    return F;
}

int main(void){
    system("cls");

    Fila *X = criarFila();

    printf("Teste #01 - Criando Fila\n\n");
    printf("A fila esta no seu endereco %d.\n", X);
    printf("Ou %x.\n", X);
    printf("O tamanho da Fila e %d. \n\n", X->Tamanho);

    //---------------------------------------------------------

    enfilerar(X, criarItem(10));
    enfilerar(X, criarItem(11));
    enfilerar(X, criarItem(12));
    enfilerar(X, criarItem(13));

    printf("Teste #02 - Inserindo\n\n");
    printf("O tamanho da Fila e %d. \n\n", X->Tamanho);
    for(int j = 1; j <= X->Tamanho; j++){
        printf("O %d elemento e %d.\n", j, posicaoFila(X,j)->Chave);
    }
    
    //---------------------------------------------------------

    printf("\nTeste #03 - Fila completa\n\n");
    exibirFila(X);

    //---------------------------------------------------------

    desenfileirar(X);

    printf("\n\nTeste #04 - removendo elemetnso da fila.\n\n");
    printf("O tamanho da Fila e %d. \n\n", X->Tamanho);
    exibirFila(X);

    return 0;
}

int filaVazia(Fila *F){
    if (F->Tamanho == 0)return SIM;
    else return NAO;
}

void enfilerar(Fila *F, Item *I){
    if (filaVazia(F)){
        F->Inicio = I;
        F->Final = I;
    }else {
        F->Final->Proximo = I;
        F->Final = I;
    }
    F->Tamanho++;
}

Item *criarItem(int C){
    Item *E = (Item *)malloc(sizeof(Item));
    if ( E == NULL){
        printf("ERRO: Problema em alocar memoria;");
        exit(1);
    }
    E->Chave = C;
    E->Proximo = NULL;
    return E;
}

Item *posicaoFila(Fila *F, int N){
    Item *Atual = F->Inicio;
    for (int i = 2; i <= N; i++)Atual = Atual->Proximo;
    return Atual;
}

void exibirFila(Fila *F){
    printf("FILA:\t");
    for(int j = 1; j <= F->Tamanho; j++){
        printf("%d\t", posicaoFila(F,j)->Chave);
    }
}

Item *desenfileirar(Fila *F){
    if(filaVazia(F)){
        printf("ERRO: a fila esta vazia!\n");
        return NULL;
    }
    
    Item *I = F->Inicio;
    F->Inicio = I->Proximo;
    F->Tamanho--;
    return I;
}