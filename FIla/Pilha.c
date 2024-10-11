#include <stdio.h>
#include <stdlib.h>

#define SIM 1
#define NAO 0

typedef struct Item{
    int Chave;
    struct Item *Anterior;
} Item;

typedef struct {
    int Tamanho;
    Item *Topo; // FIM
} Pilha;

Pilha *criarPilha();
int Vazio(Pilha *P);
Item *criarItem(int C);
Item *desempilhar(Pilha *P);
void empilhar(Pilha *P, Item *I);
void exibirPilha(Pilha *P);



int main(){
    system("cls");
    
    Pilha *MinhaPilha = criarPilha();

    //Teste 01

    printf("1) O endereco de memoria da pilha e %x.\n", MinhaPilha);
    printf("2) Tamanho da pilha e %d.\n", MinhaPilha->Tamanho);

    //Teste 02

    empilhar(MinhaPilha, criarItem(29));
    empilhar(MinhaPilha, criarItem(23));
    empilhar(MinhaPilha, criarItem(44));
    empilhar(MinhaPilha, criarItem(55));

    printf("3) NOVO Tamanho da pilha e %d.\n", MinhaPilha->Tamanho);
    printf("4) O topo da pilha e %d.\n", MinhaPilha->Topo->Chave);
    
    Item *I = desempilhar(MinhaPilha);

    printf("5) NOVO 1.0 Tamanho da pilha e %d.\n", MinhaPilha->Tamanho);
    printf("6) O elemento retirado e %d.\n", I->Chave);

    empilhar(MinhaPilha, criarItem(57));
    empilhar(MinhaPilha, criarItem(86));
    empilhar(MinhaPilha, criarItem(54));

    printf("7) Pilha: "),exibirPilha(MinhaPilha);
}

Pilha *criarPilha(){
    Pilha *P = (Pilha *)malloc(sizeof(Pilha));

    if(P == NULL){
        printf("ERRO: Não foi possivel alocar a memoria!");
        exit(1);
    }

    P->Topo = NULL;
    P->Tamanho = 0;

    return P;
}

int Vazio(Pilha *P){
    if (P->Tamanho == 0)return SIM;
    else return NAO;
}

Item *criarItem(int C){
    Item *E = (Item *)malloc(sizeof(Item));

    if ( E == NULL){
        printf("ERRO: Problema em alocar memoria;");
        exit(1);
    }
    E->Chave = C;
    E->Anterior = NULL;

    return E;
}

void empilhar(Pilha *P, Item *I){
    I->Anterior = P->Topo;
    P->Topo = I;
    P->Tamanho++;
}

Item *desempilhar(Pilha *P){
    if(Vazio(P)){
        printf("ERRO: A pilha esta vazia!\n");
        return NULL;
    }

    Item *I = P->Topo;
    P->Topo = I->Anterior;
    P->Tamanho--;

    return I;
}

void exibirPilha(Pilha *P){
    Item *I = P->Topo;
    while(I != NULL){
        printf("%d ", I->Chave);
        I = I->Anterior;
    }


}