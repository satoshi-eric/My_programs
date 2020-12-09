#include <stdlib.h>
#include <stdio.h>

// Node structure
typedef struct node 
{
    int value;
    struct node *next;
}
node;

// Node constructor
node *new_node(int value)
{
    node *node_ret = (node *)malloc(sizeof(node));
    node_ret->value = value;
    node_ret->next = NULL;
    return node_ret;
}
