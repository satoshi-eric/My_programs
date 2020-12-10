#include <stdlib.h>
#include <stdio.h>
#include "node.h"

/**
 * Data structure for linked list
 */ 
typedef struct linked_list
{
    node *init;
}
linked_list;

linked_list *new_linked_list();
void print_linked_list(linked_list *list);
void linked_list_add_node_at_begin(linked_list *list, node *node_add);
void linked_list_add_node_at_end(linked_list *list, node *node_add);
int linked_list_length(linked_list *list);
void linked_list_remove_node(linked_list *list, int position);
node *linked_list_get_node(linked_list *list, int position);

/**
 * Constructor for linked list data structure
 * @return returns a pointer to the linked list
 */ 
linked_list *new_linked_list()
{
    linked_list *linked_list_ret = (linked_list *)malloc(sizeof(linked_list));
    linked_list_ret->init = NULL;
    return linked_list_ret;
}

/**
 * Prints the linked list
 * @param list pointer to linked list to be printed
 */ 
void print_linked_list(linked_list *list)
{
    fprintf(stdout, "[");
    node *aux = list->init; // auxiliar node to iterate through list
    while (aux->next != NULL) // iterates through linked list until penultimate node
    {
        fprintf(stdout, "%d ", aux->value);
        aux = aux->next;
    }
    fprintf(stdout, "%d](%d)\n", aux->value, linked_list_length(list)); //  prints last node and the length of yhe linked list
}

/**
 * Adds a node to begin of the linked list
 * @param list pointer to linked list
 * @param node_add pointer to the node to be added
 */ 
void linked_list_add_node_at_begin(linked_list *list, node *node_add)
{
    if (list->init == NULL) // verifies if linked list is empty
        list->init = node_add;
    else 
    {
        node_add->next = list->init;
        list->init = node_add;
    }
}

/**
 * Adds a node to end of the linked list
 * @param list pointer to linked list
 * @param node_add pointer to the node to be added
 */ 
void linked_list_add_node_at_end(linked_list *list, node *node_add)
{
    if (list->init == NULL)
        list->init = node_add;
    else
    {
        node *aux = list->init;
        while (aux->next != NULL) // iterates through linked list until penultimate node
            aux = aux->next;
        aux->next = node_add;
    }
    
}

/**
 * Gets the length of the linked list
 * @param list pointer to the inked list
 * @return linked list length 
 */ 
int linked_list_length(linked_list *list)
{
    node *aux = list->init;
    int length = 0;

    while (aux != NULL)
    {
        aux = aux->next;
        length++;    
    }
    
    return length;
}

/** 
 * Remove a node from linked list by position
 * @param list pointer to the linked list
 * @param position position to remove ndoe
 */ 
void linked_list_remove_node(linked_list *list, int position)
{
    if (list->init == NULL)
        fprintf(stderr, "The list is empty\n");
    else if (position > linked_list_length(list))
        fprintf(stderr, "Position out of bounds\n");
    else if (position == 0)
        list->init = list->init->next;
    else
    {
        node *aux = list->init;
        for (int i=0; i<position-1; i++)
            aux = aux->next;
        aux->next = aux->next->next;
    }
}

/**
 * Gets the node from a linked list by position
 * @param list pointer to linked list
 * @param position position to get the node
 * @return pointer to node
 */ 
node *linked_list_get_node(linked_list *list, int position)
{
    node *aux = list->init;
    if (list->init == NULL)
        fprintf(stderr, "Empty linked list\n");
    else if(position > linked_list_length(list))
        fprintf(stderr, "Position out of bounds");
    else
        for (int i=0; i<position; i++)
        {
            aux = aux->next;
        }
        return aux;
}