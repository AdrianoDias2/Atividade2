#include <stdio.h>
#include <stdlib.h>

#define CAPACIDADE 100  // Define a capacidade máxima da lista

typedef struct {
    int *lista;
    int tamanho;
    int capacidade;
} ListaSequencial;

// Função para criar uma lista vazia
ListaSequencial* criar_lista(int capacidade) {
    ListaSequencial *lista = (ListaSequencial*)malloc(sizeof(ListaSequencial));
    lista->lista = (int*)malloc(capacidade * sizeof(int));
    lista->tamanho = 0;
    lista->capacidade = capacidade;
    return lista;
}

// Função para verificar se a lista está vazia
int esta_vazia(ListaSequencial *lista) {
    return lista->tamanho == 0;
}

// Função para verificar se a lista está cheia
int esta_cheia(ListaSequencial *lista) {
    return lista->tamanho == lista->capacidade;
}

// Função para obter o tamanho da lista
int obter_tamanho(ListaSequencial *lista) {
    return lista->tamanho;
}

// Função para obter o valor de um elemento em uma determinada posicao
int obter_elemento(ListaSequencial *lista, int posicao) {
    if (posicao >= 1 && posicao <= lista->tamanho) {
        return lista->lista[posicao - 1];
    } else {
        printf("posicao invalida.\n");
        exit(1);
    }
}

// Função para modificar o valor de um elemento em uma determinada posicao
void modificar_elemento(ListaSequencial *lista, int posicao, int valor) {
    if (posicao >= 1 && posicao <= lista->tamanho) {
        lista->lista[posicao - 1] = valor;
    } else {
        printf("posicao invalida.\n");
        exit(1);
    }
}

// Função para inserir um elemento em uma determinada posicao
void inserir_elemento(ListaSequencial *lista, int posicao, int valor) {
    if (esta_cheia(lista)) {
        printf("Lista cheia.\n");
        return 0;
    }
    if (posicao < 1 || posicao > lista->tamanho + 1) {
        printf("posicao invalida.\n");
        return 0;
    }
    for (int i = lista->tamanho; i >= posicao; i--) {
        lista->lista[i] = lista->lista[i - 1];
    }
    lista->lista[posicao - 1] = valor;
    lista->tamanho++;
}

// Função para retirar um elemento de uma determinada posicao
void retirar_elemento(ListaSequencial *lista, int posicao) {
    if (posicao < 1 || posicao > lista->tamanho) {
        printf("Posicao invalida.\n");
        return;
    }
    for (int i = posicao - 1; i < lista->tamanho - 1; i++) {
        lista->lista[i] = lista->lista[i + 1];
    }
    lista->tamanho--;
}

// Função para liberar a memória alocada pela lista
void liberar_lista(ListaSequencial *lista) {
    free(lista->lista);
    free(lista);
}

int main() {
    ListaSequencial *lista = criar_lista(CAPACIDADE);

    // Testes básicos
    inserir_elemento(lista, 1, 10); // Insere 10 na posicao 1
    inserir_elemento(lista, 2, 20); // Insere 20 na posicao 2
    inserir_elemento(lista, 3, 30); // Insere 30 na posicao 3

    printf("Elemento na posicao 2: %d\n", obter_elemento(lista, 2));

    modificar_elemento(lista, 2, 25);
    printf("Elemento na posicao 2 apos modificacao: %d\n", obter_elemento(lista, 2));

    retirar_elemento(lista, 2);
    printf("Elemento na posicao 2 apos remocao: %d\n", obter_elemento(lista, 2));



    liberar_lista(lista);
    return 0;
}
