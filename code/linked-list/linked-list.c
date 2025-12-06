#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}
node;

typedef struct linked_list{
    node* head;
}
linked_list;