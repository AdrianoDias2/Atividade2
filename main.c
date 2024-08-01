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

// Função para obter o valor de um elemento em uma determinada posição
int obter_elemento(ListaSequencial *lista, int posicao) {
    if (posicao >= 1 && posicao <= lista->tamanho) {
        return lista->lista[posicao - 1];
    } else {
        printf("Posição inválida.\n");
        exit(1);
    }
}

// Função para modificar o valor de um elemento em uma determinada posição
void modificar_elemento(ListaSequencial *lista, int posicao, int valor) {
    if (posicao >= 1 && posicao <= lista->tamanho) {
        lista->lista[posicao - 1] = valor;
    } else {
        printf("Posição inválida.\n");
        exit(1);
    }
}

// Função para inserir um elemento em uma determinada posição
void inserir_elemento(ListaSequencial *lista, int posicao, int valor) {
    if (esta_cheia(lista)) {
        printf("Lista cheia.\n");
        return;
    }
    if (posicao < 1 || posicao > lista->tamanho + 1) {
        printf("Posição inválida.\n");
        return;
    }
    for (int i = lista->tamanho; i >= posicao; i--) {
        lista->lista[i] = lista->lista[i - 1];
    }
    lista->lista[posicao - 1] = valor;
    lista->tamanho++;
}

// Função para retirar um elemento de uma determinada posição
void retirar_elemento(ListaSequencial *lista, int posicao) {
    if (posicao < 1 || posicao > lista->tamanho) {
        printf("Posição inválida.\n");
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
    inserir_elemento(lista, 1, 10); // Insere 10 na posição 1
    inserir_elemento(lista, 2, 20); // Insere 20 na posição 2
    inserir_elemento(lista, 3, 30); // Insere 30 na posição 3

    printf("Elemento na posição 2: %d\n", obter_elemento(lista, 2));

    modificar_elemento(lista, 2, 25);
    printf("Elemento na posição 2 após modificação: %d\n", obter_elemento(lista, 2));

    retirar_elemento(lista, 2);
    printf("Elemento na posição 2 após remoção: %d\n", obter_elemento(lista, 2));

    liberar_lista(lista);
    return 0;
}
