/*
Define a doubly linked list of heap-allocated strings. Write functions insert, find and delete items from it.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node 
{
    char *string;
    struct Node *next;
    struct Node *prev;
} Node;


// Insert a node after the previous one which is provided. If at the start previous is NULL
void Insert(Node **list, Node *prev, char *string);

// Deletes this node from the list
void Delete(Node **list, Node *node);

// Finds the node with the given value
Node *Find(Node *list, char *string);

// Free the memory of the list
void Free(Node **list);

// Prints the list 
void dump(Node* list);

int main(void)
{
    Node* list = NULL;
    Insert(&list, NULL, "four");
    Insert(&list, NULL, "one");
    Insert(&list, Find(list, "one"), "two");
    Insert(&list, Find(list, "two"), "three");
    
    dump(list);
    printf("-- delete three --\n");
    Delete(&list, Find(list, "three"));
    dump(list);

    printf("-- delete one --\n");
    Delete(&list, Find(list, "one"));
    dump(list);

    Free(&list);

    return 0;
}

void Insert(Node **list, Node *prev, char *string)
{
    Node *new = malloc(sizeof(Node));
    new->string = malloc(strlen(string) + 1);
    strcpy(new->string, string);

    if (prev == NULL)
    {
        if (*list != NULL)
        {
            (*list)->prev = new;
        }
        new->next = (*list);
        new->prev = NULL;
        *list = new;
    }
    else
    {
        new->next = prev->next;
        prev->next = new;
        new->prev = prev;
        if (new->next)
        {
            new->next->prev = new;
        }
    }
}

void Delete(Node **list, Node *node)
{
    if(node->next == NULL)
    {
        node->prev->next = NULL;
    }
    if (node->prev == NULL)
    {
        *list = (*list)->next;
        node->next->prev = NULL;
    }
    else 
    {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    free(node->string);
    free(node);
}

Node *Find(Node *list, char *string)
{
    while(list)
    {
        if (strcmp(string, list->string) == 0)
        {
            return list;
        }
        list = list->next;
    }

    return NULL;
}

void Free(Node **list)
{
    if (list == NULL)
    {
        return;
    }
    Node *temp;
    while (list)
    {
        temp = *list;
        *list = (*list)->next;
        free(temp->string);
        free(temp);
    }
}

void dump(Node* list) 
{
  while (list != NULL) 
  {
    printf("%p [prev %p next %p] %s\n",
           list, list->prev, list->next, list->string);
    list = list->next;
  }
}