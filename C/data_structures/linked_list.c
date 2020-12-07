#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
	int value;
	struct Node *next;
}
Node;

Node *new_node(int value)
{
	Node *node = (Node *) malloc(sizeof(Node));
	node->value = value;
	node->next = NULL;
	return node;
}

void print_node(Node *node, char *filename)
{
	char *output;
	if (filename == NULL)
		output = 
