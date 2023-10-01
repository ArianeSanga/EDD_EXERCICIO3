#include "fila.h"
#include "fila_impl.c"

int main(int argc, char const *argv[]){
    Queue fila;
    Queue auxiliar;
    Element number;

    init(&fila);
    for(int i = 0; i != 20; i++){
        printf("Digite numero: ");
        scanf("%d", &number);

        enqueue(fila, number);
    }

    init(&auxiliar);
    while( ! is_empty(fila)){
        number = dequeue(fila);
        if(number == 0 || number % 2 != 0){
            enqueue(auxiliar, number);
        }
    }

    while( ! is_empty(auxiliar) ){
        number = dequeue(auxiliar);
        printf("%d, ", number);
        enqueue(fila, number);
    }

    return 0;
}
