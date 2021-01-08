#include <stdlib.h>
#include <stdio.h>
#include "node.h"

typedef struct stack
{
    node *init;
}
stack;

stack *new_stack() 
{
    stack *ret_stack = (stack *)malloc(sizeof(stack));
    ret_stack->init = NULL;
    return ret_stack;
}

void print_stack(stack *print_stack) 
{
    fprintf(stdout, "[");
    node *aux = print_stack->init;
    while (aux->next != NULL) 
    {
        fprintf(stdout, "%d ", aux->value);
        aux = aux->next;
    }
    fprintf(stdout, "%d]", aux->value);
}

void stack_add_node(stack *)