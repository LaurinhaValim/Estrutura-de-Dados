#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

t_stack* createStack(int capacity) {
    t_stack *stack = malloc(sizeof(t_stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = malloc(sizeof(int) * capacity);
    return stack;
}

int isStackEmpty(t_stack *stack) {
    return stack->top == -1;
}

int isStackFull(t_stack *stack) {
    return stack->top == stack->capacity - 1;
}

void push(t_stack *stack, int value) {
    if (!isStackFull(stack)) {
        stack->top++;
        stack->data[stack->top] = value;
    }
}

int pop(t_stack *stack) {
    if (!isStackEmpty(stack)) {
        int value = stack->data[stack->top];
        stack->top--;
        return value;
    }
    return -1;
}

void destroyStack(t_stack *stack) {
    if (stack != NULL) {
        free(stack->data);
        free(stack);
    }
}