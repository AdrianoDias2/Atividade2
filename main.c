#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"

int main() {
    ListaSequencial *lista = criar_lista(CAPACIDADE);

    // Testes básicos
    inserir_elemento(lista, 1, 10); 
    inserir_elemento(lista, 2, 20); 
    inserir_elemento(lista, 3, 30); 
    inserir_elemento(lista, 4, 100); 
    inserir_elemento(lista, 5, 200); 
    inserir_elemento(lista, 6, 300); 

    printf("Elemento na posicao 2: %d\n", obter_elemento(lista, 2));
    printf("Elemento na posicao 5: %d\n", obter_elemento(lista, 5));

    
    modificar_elemento(lista, 2, 25);
    printf("Elemento na posicao 2 apos modificacao: %d\n", obter_elemento(lista, 2));

    modificar_elemento(lista, 5, 90);
    printf("Elemento na posicao 5 apos modificacao: %d\n", obter_elemento(lista, 5));
    
    retirar_elemento(lista, 2);
     printf("Elemento na posicao 2 apos remocao: %d\n", obter_elemento(lista, 2));


    liberar_lista(lista);
    return 0;
}
