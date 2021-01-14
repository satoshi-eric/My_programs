#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
} Node;

Node *new_node(int value)
{
    Node *ret = (Node *) malloc(sizeof(Node));
    ret->value = value;
    ret->left = NULL;
    ret->right = NULL;
    return ret;
}

typedef struct Tree
{
    Node *root;
} Tree;

Tree *new_tree()
{
    Tree *ret = (Tree *) malloc(sizeof(Tree));
    ret->root = NULL;
    return ret;
}

void add_node(Tree *tree, int value)
{
    if (tree->root == NULL)
    {
        tree->root = new_node(value);
    }
    else
    {
        
    }
}

void print_tree(Node *node)
{
    if (node != NULL)
    {
        print_tree(node->left);
        printf("%d\n", node->value);
        print_tree(node->right);
    }
}

#endif