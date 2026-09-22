#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "quickSort.h"

static void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

static int partition(int *array, int low, int high) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return i + 1;
}

void quickSortIterative(int *array, int size) {
    if (size <= 1) {
        return;
    }

    t_stack *stack = createStack(size);

    push(stack, 0);
    push(stack, size - 1);

    while (!isStackEmpty(stack)) {
        int high = pop(stack);
        int low = pop(stack);

        int p = partition(array, low, high);

        int leftSize = p - 1 - low;
        int rightSize = high - (p + 1);

        if (leftSize > rightSize) {
            if (low < p - 1) {
                push(stack, low);
                push(stack, p - 1);
            }
            if (p + 1 < high) {
                push(stack, p + 1);
                push(stack, high);
            }
        } else {
            if (p + 1 < high) {
                push(stack, p + 1);
                push(stack, high);
            }
            if (low < p - 1) {
                push(stack, low);
                push(stack, p - 1);
            }
        }
    }

    destroyStack(stack);
}