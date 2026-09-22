/*Integrantes: 
Nome: Dayani de Jesus - SC3046761
Nome: Laura Valim     - SC3046605
Nome: Weslley Viana   - SC3039757
*/
#include <stdio.h>
#include <stdlib.h>
#include "OrderList.h"

int main() {
    int max;
    printf("Digite a quantidade de elementos da lista: ");
    scanf("%d", &max);

    t_ordered_list *list1 = createList(max);
    t_ordered_list *list2 = createList(max);

    int valor;

    printf("Digite elementos para inserir na lista 1 (-1 para parar):\n");
    while (1) {
        printf("Digite um elemento: ");
        scanf("%d", &valor);

        if (valor == -1) {
            break;
        }

        insertList(list1, valor);
        printList(list1);
    }

    printf("\nDigite elementos para inserir na lista 2 (-1 para parar):\n");
    while (1) {
        printf("Digite um elemento: ");
        scanf("%d", &valor);

        if (valor == -1) {
            break;
        }

        insertList(list2, valor);
        printList(list2);
    }

    int i;
    printf("\nDigite um indice para remover da lista 1: ");
    scanf("%d", &i);
    if (removeByIndex(list1, i)) {
        printf("Elemento removido com sucesso!\n");
        printList(list1);
    } else {
        printf("Indice invalido! Digite um indice entre 0 e %d.\n", sizeList(list1) - 1);
    }

    printf("\nDigite um elemento para remover na lista 1: ");
    scanf("%d", &i);
    if (removeByElement(list1, i)) {
        printf("Elemento removido com sucesso!\n");
    } else {
        printf("Elemento nao encontrado na lista!\n");
    }
    printList(list1);

    printf("\nDigite um elemento para buscar na lista 1: ");
    scanf("%d", &i);
    if (searchList(list1, i)) {
        printf("Elemento encontrado!\n");
    } else {
        printf("Elemento nao encontrado!\n");
    }

    printf("\nDigite um elemento para encontrar seu indice na lista 1: ");
    scanf("%d", &i);
    int idx = indexOf(list1, i);
    if (idx != -1) {
        printf("O indice do elemento e: %d\n", idx);
    } else {
        printf("Elemento nao presente na lista.\n");
    }

    printf("\nDigite um indice para encontrar seu elemento na lista 1: ");
    scanf("%d", &i);
    int elem = getList(list1, i);
    if (elem != -1) {
        printf("O elemento nesse indice e: %d\n", elem);
    } else {
        printf("Indice invalido.\n");
    }

    printf("\nDigite um elemento para contar sua quantidade na lista 1: ");
    scanf("%d", &i);
    printf("O elemento aparece %d vez(es) na lista.\n", countList(list1, i));

    printf("\nO tamanho da lista 1 e: %d\n", sizeList(list1));

    printf("\nLista 1:\n");
    printList(list1);

    printf("Lista 2:\n");
    printList(list2);

    t_ordered_list *mergedList = mergeLists(list1, list2);
    printf("Lista resultante da juncao:\n");
    printList(mergedList);

    printf("As listas sao iguais? %s\n", equalsLists(list1, list2) ? "Sim" : "Nao");
    printf("A lista 1 esta vazia? %s\n", isEmpty(list1) ? "Sim" : "Nao");

    printf("\nLimpando a lista 1...\n");
    clearList(list1);
    printList(list1);

    list1 = destroyList(list1);
    list2 = destroyList(list2);
    mergedList = destroyList(mergedList);

    return 0;
}