/*
 Integrantes do Grupo:
Nome: Dayani de Jesus - SC3046761
Nome: Laura Valim     - SC3046605
Nome: Weslley Viana   - SC3039757

 A estrategia discutida faz total sentido e foi devidamente implementada.
 Ao utilizar a versao não recursiva do QuickSort com uma pilha explicita,
 podemos controlar manualmente a ordem em que os subvetores sao processados.
 Empilhando os índices da partição maior primeiro, garantimos que a partição menor
 seja empilhada por último e, consequentemente, processada antes
 Isso reduz a profundidade máxima ocupada na pilha de O(n) para O(log n), evitando o estouro
 de pilha mesmo nos piores casos de particionamento.
*/

#include <stdio.h>
#include <stdlib.h>
#include "quickSort.h"

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 0;
    }

    int *array = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    quickSortIterative(array, n);

    for (int i = 0; i < n; i++) {
        printf("%d", array[i]);
    }
    printf("\n");

    free(array);
    return 0;
}