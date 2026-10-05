#include <stdio.h>
#include "tree.h"

int main()
{
    Tree tree;
    int choice;
    int key;

    initTree(&tree);

    while (1)
    {
        printf("\n========== BST MENU ==========\n");
        printf("1. Insert a key\n");
        printf("2. Delete a key\n");
        printf("3. Display tree (Inorder)\n");
        printf("4. Exit\n");
        printf("==============================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);

                insert(&tree, key);
                break;

            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &key);

                delete_key(&tree, key);
                break;

            case 3:
                display(&tree);
                break;

            case 4:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}