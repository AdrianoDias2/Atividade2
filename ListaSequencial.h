#ifndef LISTA_SEQUENCIAL
#define LISTA_SEQUENCIAL

#define CAPACIDADE 100

typedef struct {
    int *lista;
    int tamanho;
    int capacidade;
} ListaSequencial;


ListaSequencial* criar_lista(int capacidade);


int esta_vazia(ListaSequencial *lista);

int esta_cheia(ListaSequencial *lista); 

int obter_tamanho(ListaSequencial *lista); 

int obter_elemento(ListaSequencial *lista, int posicao);

void modificar_elemento(ListaSequencial *lista, int posicao, int valor);

void inserir_elemento(ListaSequencial *lista, int posicao, int valor); 

void retirar_elemento(ListaSequencial *lista, int posicao); 

void liberar_lista(ListaSequencial *lista);


#endif