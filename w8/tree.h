#ifndef TREE_H
#define TREE_H
#include "stack.h"

typedef struct
{
    int key;
    int left;
    int right;
    int used;
} Node;

typedef struct
{
    Node nodes[MAX_SIZE];
    int root;
    Stack freeStack;
} Tree;

void initTree(Tree *tree);

void insert(Tree *tree, int key);
void delete_key(Tree *tree, int key);

void inorder(Tree *tree);
void display(Tree *tree);

#endif