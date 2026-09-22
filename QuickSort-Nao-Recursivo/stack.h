#ifndef STACK_H
#define STACK_H

typedef struct {
    int top;
    int capacity;
    int *data;
} t_stack;

t_stack* createStack(int capacity);
int isStackEmpty(t_stack *stack);
int isStackFull(t_stack *stack);
void push(t_stack *stack, int value);
int pop(t_stack *stack);
void destroyStack(t_stack *stack);

#endif