#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "queue.h"

/* ---------- starter functions ---------- */
void init(tree_t *ptr_tree) { ptr_tree->root_ = NULL; }

static void deinit_recursive(tree_node_t *root)
{
    if (root == NULL) return;
    deinit_recursive(root->left_);
    deinit_recursive(root->right_);
    free(root);
}
void deinit(tree_t *ptr_tree) { deinit_recursive(ptr_tree->root_); ptr_tree->root_ = NULL; }

static tree_node_t *create_node(int key)
{
    tree_node_t *n = (tree_node_t *)malloc(sizeof(tree_node_t));
    if (n != NULL) { n->key_ = key; n->left_ = n->right_ = NULL; }
    return n;
}

void insert(tree_t *ptr_tree, int key)
{
    tree_node_t **pp = &ptr_tree->root_;
    while (*pp != NULL)
        pp = (key < (*pp)->key_) ? &(*pp)->left_ : &(*pp)->right_;
    *pp = create_node(key);
}

static void inorder_recursive(tree_node_t *root)
{
    if (root == NULL) return;
    inorder_recursive(root->left_);
    printf("%d ", root->key_);
    inorder_recursive(root->right_);
}
void disp(tree_t *ptr_tree)
{
    printf("Inorder     : ");
    inorder_recursive(ptr_tree->root_);
    printf("\n");
}

/* ---------- Part A4 ---------- */
void level_order(tree_t *ptr_tree)
{
    queue_t q;
    init_queue(&q);

    printf("Level order : ");
    enqueue(&q, ptr_tree->root_);
    while (!is_empty(&q))
    {
        tree_node_t *temp = dequeue(&q);
        if (temp != NULL)
        {
            printf("%d ", temp->key_);
            enqueue(&q, temp->left_);
            enqueue(&q, temp->right_);
        }
    }
    printf("\n");
    deinit_queue(&q);
}

/* ---------- Part B1 ---------- */
void level_order_lines(tree_t *ptr_tree)
{
    if (ptr_tree->root_ == NULL) { printf("(empty tree)\n"); return; }

    queue_t q;  init_queue(&q);
    enqueue(&q, ptr_tree->root_);
    int cur = 1, next = 0, level = 0, printed = 0;

    while (!is_empty(&q))
    {
        tree_node_t *temp = dequeue(&q);
        --cur;
        if (temp != NULL)
        {
            if (printed == 0) printf("  Level %d : ", level);
            printf("%4d", temp->key_);
            ++printed;
            enqueue(&q, temp->left_);          /* TODO 1 */
            enqueue(&q, temp->right_);
            next += 2;                         /* TODO 2 */
        }
        if (cur == 0)
        {
            if (printed > 0) { printf("\n"); ++level; }   /* TODO 3 */
            cur = next; next = 0; printed = 0;            /* TODO 4 */
        }
    }
    deinit_queue(&q);
}

/* ---------- Part B2 ---------- */
typedef struct
{
    char **grid;
    int rows, cols;
    int cell;      /* cell width */
    int counter;   /* inorder position counter */
} canvas_t;

static int height_recursive(tree_node_t *root)
{
    if (root == NULL) return 0;
    int l = height_recursive(root->left_), r = height_recursive(root->right_);
    return 1 + (l > r ? l : r);
}
static int count_recursive(tree_node_t *root)
{
    return root == NULL ? 0 : 1 + count_recursive(root->left_) + count_recursive(root->right_);
}
static int digits(int k) { char b[32]; return (int)sprintf(b, "%d", k); }
static int max_width_recursive(tree_node_t *root)
{
    if (root == NULL) return 0;
    int w = digits(root->key_);
    int l = max_width_recursive(root->left_), r = max_width_recursive(root->right_);
    if (l > w) w = l;
    if (r > w) w = r;
    return w;
}

static int place(tree_node_t *root, int depth, canvas_t *cv)
{
    if (root == NULL) return -1;

    int lcol = place(root->left_, depth + 1, cv);       /* left subtree  */
    int col  = cv->counter++ * cv->cell + 2;            /* inorder column */
    char buf[32];
    int len = sprintf(buf, "%d", root->key_);
    memcpy(&cv->grid[2 * depth][col], buf, len);        /* this key      */
    int rcol = place(root->right_, depth + 1, cv);      /* right subtree */

    int row = 2 * depth + 1;                            /* branch row    */
    if (lcol >= 0)
    {
        for (int c = lcol; c <= col; ++c) cv->grid[row][c] = '-';
        cv->grid[row][lcol] = '+';
    }
    if (rcol >= 0)
    {
        for (int c = col; c <= rcol; ++c) cv->grid[row][c] = '-';
        cv->grid[row][rcol] = '+';
    }
    if (lcol >= 0 || rcol >= 0) cv->grid[row][col] = '+';
    return col;
}

void disp_tree(tree_t *ptr_tree)
{
    if (ptr_tree->root_ == NULL) { printf("(empty tree)\n"); return; }

    int h = height_recursive(ptr_tree->root_);
    int n = count_recursive(ptr_tree->root_);
    canvas_t cv;
    cv.cell = max_width_recursive(ptr_tree->root_) + 2;
    cv.rows = 2 * h - 1;
    cv.cols = n * cv.cell + 2 + cv.cell;
    cv.counter = 0;
    cv.grid = (char **)malloc(cv.rows * sizeof(char *));
    for (int r = 0; r < cv.rows; ++r)
    {
        cv.grid[r] = (char *)malloc(cv.cols + 1);
        memset(cv.grid[r], ' ', cv.cols);
        cv.grid[r][cv.cols] = '\0';
    }

    place(ptr_tree->root_, 0, &cv);

    for (int r = 0; r < cv.rows; ++r)
    {
        int e = cv.cols - 1;
        while (e >= 0 && cv.grid[r][e] == ' ') --e;     /* trim trailing */
        cv.grid[r][e + 1] = '\0';
        printf("%s\n", cv.grid[r]);
        free(cv.grid[r]);
    }
    free(cv.grid);
}
