#include <stdio.h>
#include "tree.h"

void initTree(Tree *tree)
{
    int i;
    tree->root = -1;
    initStack(&tree->freeStack);
    for (i = MAX_SIZE - 1; i >= 0; i--)
    {
        tree->nodes[i].used = 0;
        tree->nodes[i].left = -1;
        tree->nodes[i].right = -1;

        push(&tree->freeStack, i);
    }
}

void insert(Tree *tree, int key)
{
    int newIndex;
    int current;
    int parent;
    if (!pop(&tree->freeStack, &newIndex))
    {
        return;
    }

    tree->nodes[newIndex].key = key;
    tree->nodes[newIndex].left = -1;
    tree->nodes[newIndex].right = -1;
    tree->nodes[newIndex].used = 1;

    if (tree->root == -1)
    {
        tree->root = newIndex;
        printf("Inserted %d at index %d.\n", key, newIndex);
        return;
    }

    current = tree->root;
    parent = -1;

    while (current != -1)
    {
        parent = current;
        if (key < tree->nodes[current].key)
        {
            current = tree->nodes[current].left;
        }
        else if (key > tree->nodes[current].key)
        {
            current = tree->nodes[current].right;
        }
        else
        {
            printf("Duplicate key %d. Insertion cancelled.\n", key);
            tree->nodes[newIndex].used = 0;
            push(&tree->freeStack, newIndex);
            return;
        }
    }

    if (key < tree->nodes[parent].key)
    {
        tree->nodes[parent].left = newIndex;
    }
    else
    {
        tree->nodes[parent].right = newIndex;
    }
    printf("Inserted %d at index %d.\n", key, newIndex);
}

void inorder(Tree *tree)
{
    if (tree->root == -1)
    {
        printf("Tree is empty.\n");
        return;
    }

    int stack[MAX_SIZE];
    int top = -1;
    int current = tree->root;

    while (current != -1 || top != -1)
    {
        while (current != -1)
        {
            stack[++top] = current;
            current = tree->nodes[current].left;
        }
        current = stack[top--];
        printf("%d ", tree->nodes[current].key);
        current = tree->nodes[current].right;
    }

    printf("\n");
}

void display(Tree *tree)
{
    printf("Inorder: ");
    inorder(tree);
}

void delete_key(Tree *tree, int key)
{
    int current;
    int parent;
    int successor;
    int successorParent;
    int replacement;
    int deletedIndex;

    current = tree->root;
    parent = -1;

    while (current != -1 && tree->nodes[current].key != key)
    {
        parent = current;

        if (key < tree->nodes[current].key)
        {
            current = tree->nodes[current].left;
        }
        else
        {
            current = tree->nodes[current].right;
        }
    }
    if (current == -1)
    {
        printf("Key %d not found.\n", key);
        return;
    }
    deletedIndex = current;

    if (tree->nodes[current].left != -1 &&
        tree->nodes[current].right != -1)
    {
        successorParent = current;
        successor = tree->nodes[current].right;

        while (tree->nodes[successor].left != -1)
        {
            successorParent = successor;
            successor = tree->nodes[successor].left;
        }
        tree->nodes[current].key = tree->nodes[successor].key;
        deletedIndex = successor;

        if (tree->nodes[successor].left != -1)
        {
            replacement = tree->nodes[successor].left;
        }
        else
        {
            replacement = tree->nodes[successor].right;
        }

        if (tree->nodes[successor].right != -1 ||
            tree->nodes[successor].left != -1)
        {
            if (tree->nodes[successorParent].left == successor)
            {
                tree->nodes[successorParent].left = replacement;
            }
            else
            {
                tree->nodes[successorParent].right = replacement;
            }
        }
        else
        {
            if (tree->nodes[successorParent].left == successor)
            {
                tree->nodes[successorParent].left = -1;
            }
            else
            {
                tree->nodes[successorParent].right = -1;
            }
        }
    }
    else
    {
        if (tree->nodes[current].left != -1)
        {
            replacement = tree->nodes[current].left;
        }
        else
        {
            replacement = tree->nodes[current].right;
        }
        if (parent == -1)
        {
            tree->root = replacement;
        }
        else
        {
            if (tree->nodes[parent].left == current)
            {
                tree->nodes[parent].left = replacement;
            }
            else
            {
                tree->nodes[parent].right = replacement;
            }
        }
    }

    tree->nodes[deletedIndex].used = 0;
    tree->nodes[deletedIndex].left = -1;
    tree->nodes[deletedIndex].right = -1;

    push(&tree->freeStack, deletedIndex);
    printf("Deleted key %d from index %d.\n", key, deletedIndex);
}