#include "fila.h"
#include "fila.c"

int main() {
    Queue fila_normal;
    Queue fila_preferencial;
    Element number = 0;
    Element caixa = 1;
    Element numero_cliente = 1;

    init(&fila_normal);
    init(&fila_preferencial);

    while(number != 4) {
        printf("--------------------\n");
        printf("Escolha uma opção:\n");
        printf("1. Pegar ficha normal\n");
        printf("2. Pegar ficha prioritária\n");
        printf("3. Caixa chama próximo cliente\n");
        printf("4. Fechar programa\n");
        printf("-> ");
        scanf("%d", &number);

        if(number == 4) {
            break;
        }

        switch (number) {
            case 1:
                printf("Cliente %d\n",numero_cliente);
                printf("Fila normal\n");
                enqueue(&fila_normal,numero_cliente++);
                break;
            case 2:
                printf("Cliente %d\n",numero_cliente);
                printf("Fila preferencial\n");
                enqueue(&fila_preferencial,numero_cliente++);
                break;
            case 3:
                printf("Qual caixa?\n");
                scanf("%d", &caixa);
                if(caixa >= 1 && caixa <= 10){
                    if(!is_empty(fila_preferencial)&& caixa <= 3){
                        printf("Caixa %d chama o cliente %d da fila preferencial\n",caixa,dequeue(&fila_preferencial));
                    }else if(!is_empty(fila_normal)){
                        printf("Caixa %d chama o cliente %d da fila normal\n",caixa,dequeue(&fila_normal));
                    }else if(!is_empty(fila_preferencial)){
                        printf("Caixa %d chama o cliente %d da fila prioritária\n", caixa, dequeue(&fila_preferencial));
                    }else{
                        printf("Caixa %d: Não há clientes nas filas.\n", caixa);
                    }
                }else {
                    printf("Caixa inválido. Informe um número de 1 a 10.\n");
                }

                break;
            case 4:
                printf("Saindo do programa.\n");
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    }

    return 0;
}