#include "circulo.h"

int main() {
    Queue fila;
    init(&fila);

    int quantidade_soldados = 40;

    Element soldado;
    for (int i = 0; i < quantidade_soldados; i++) {
        printf("Digite o nome do soldado:\n");
        scanf("%s", soldado);
        enqueue(&fila, soldado);
    }
    
    Element soldado1, soldado2, soldado3;
    int c = 13;
    while (c > 0) {
        dequeue(&fila, soldado1);
        dequeue(&fila, soldado2);
        dequeue(&fila, soldado3);
        printf("%s, %s e %s foram eliminados.\n", soldado1, soldado2, soldado3);
        c--;
    }

    Element sobrevivente;
    if (dequeue(&fila, sobrevivente)) {
        printf("O sobrevivente é: %s\n", sobrevivente);
    } else {
        printf("A fila está vazia.\n");
    }

    return 0;
}
