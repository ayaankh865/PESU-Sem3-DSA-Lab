#ifndef TREE_H
#define TREE_H

typedef struct tree_node
{
    int key_;
    struct tree_node *left_;
    struct tree_node *right_;
} tree_node_t;

typedef struct
{
    tree_node_t *root_;
} tree_t;

void init(tree_t *ptr_tree);
void deinit(tree_t *ptr_tree);
void insert(tree_t *ptr_tree, int key);
void disp(tree_t *ptr_tree);               /* inorder */
void level_order(tree_t *ptr_tree);        /* Part A  */
void level_order_lines(tree_t *ptr_tree);  /* Part B1 */
void disp_tree(tree_t *ptr_tree);          /* Part B2 */

#endif
