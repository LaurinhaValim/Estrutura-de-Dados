/*Integrantes: 
Nome: Dayani de Jesus - SC3046761
Nome: Laura Valim     - SC3046605
Nome: Weslley Viana   - SC3039757

1. Ponto fortes e fracos de uma lista ordenada:
Pontos Fortes: A busca por elementos é extremamente rápida utilizando a Busca Binária(Complexidade O(log n)), permite localizar itens e verificar a existência de forma muito mais eficiente.
Pontos Fracos: A inserção e a remoção exigem o deslocamento de elementos para manter a ordem (complexidade O(n)), tornando essas operações custosas.


2. Estratégia para o aumento de memória:
Foi adotada a estratégia do fator de crescimento exponencial. Quando o limite de armazenamento é atingido, o tamanho alocado é multiplicado por 2 utilizando a função realloc(). Sendo assim, reduz o custo amortizado das realocações frequentes.
*/

#include <stdio.h>
#include <stdlib.h>
#include "OrderList.h"

t_ordered_list* createList(int max) {
    t_ordered_list *list = malloc(sizeof(t_ordered_list));
    list->max = max;
    list->n = 0;
    list->items = malloc(sizeof(int) * max);
    return list;
}

int isFull(t_ordered_list *list) {
    return list->n == list->max;
}

int isEmpty(t_ordered_list *list) {
    return list->n == 0;
}

int sizeList(t_ordered_list *list) {
    return list->n;
}

t_ordered_list* reallocateList(t_ordered_list *list) {
    int newMax = list->max * 2;
    int *temp = realloc(list->items, sizeof(int) * newMax);
    if (temp != NULL) {
        list->items = temp;
        list->max = newMax;
    }
    return list;
}

int insertList(t_ordered_list *list, int elem) {
    if (isFull(list)) {
        reallocateList(list);
    }

    int i = list->n - 1;
    while (i >= 0 && list->items[i] > elem) {
        list->items[i + 1] = list->items[i];
        i--;
    }
    list->items[i + 1] = elem;
    list->n++;
    return 1;
}

int removeByIndex(t_ordered_list *list, int index) {
    if (index < 0 || index >= list->n) {
        return 0;
    }

    for (int i = index; i < list->n - 1; i++) {
        list->items[i] = list->items[i + 1];
    }
    list->n--;
    return 1;
}

int indexOf(t_ordered_list *list, int elem) {
    int inicio = 0;
    int fim = list->n - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (list->items[meio] == elem) {
            return meio;
        } else if (list->items[meio] < elem) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

int searchList(t_ordered_list *list, int elem) {
    return indexOf(list, elem) != -1;
}

int removeByElement(t_ordered_list *list, int elem) {
    int index = indexOf(list, elem);
    if (index == -1) {
        return 0;
    }
    return removeByIndex(list, index);
}

int getList(t_ordered_list *list, int index) {
    if (index < 0 || index >= list->n) {
        return -1;
    }
    return list->items[index];
}

int countList(t_ordered_list *list, int elem) {
    int count = 0;
    int index = indexOf(list, elem);

    if (index == -1) {
        return 0;
    }

    int i = index;
    while (i >= 0 && list->items[i] == elem) {
        count++;
        i--;
    }

    i = index + 1;
    while (i < list->n && list->items[i] == elem) {
        count++;
        i++;
    }

    return count;
}

t_ordered_list* mergeLists(t_ordered_list *list1, t_ordered_list *list2) {
    int i = 0, j = 0, k = 0;
    int totalSize = list1->n + list2->n;
    t_ordered_list *mergedList = createList(totalSize == 0 ? 1 : totalSize);

    while (i < list1->n && j < list2->n) {
        if (list1->items[i] < list2->items[j]) {
            mergedList->items[k++] = list1->items[i++];
        } else {
            mergedList->items[k++] = list2->items[j++];
        }
    }

    while (i < list1->n) {
        mergedList->items[k++] = list1->items[i++];
    }

    while (j < list2->n) {
        mergedList->items[k++] = list2->items[j++];
    }

    mergedList->n = k;
    return mergedList;
}

int equalsLists(t_ordered_list *list1, t_ordered_list *list2) {
    if (list1->n != list2->n) {
        return 0;
    }

    for (int i = 0; i < list1->n; i++) {
        if (list1->items[i] != list2->items[i]) {
            return 0;
        }
    }
    return 1;
}

void printList(t_ordered_list *list) {
    printf("Lista: ");
    for (int i = 0; i < list->n; i++) {
        printf("%d ", list->items[i]);
    }
    printf("\n");
}

int clearList(t_ordered_list *list) {
    list->n = 0;
    return 1;
}

t_ordered_list* destroyList(t_ordered_list *list) {
    if (list != NULL) {
        free(list->items);
        free(list);
    }
    return NULL;
}