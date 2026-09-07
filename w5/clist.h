#ifndef CLIST_H
#define CLIST_H

#define NAME_SIZE 100

struct node
{
    int key_;
    char name_[NAME_SIZE];
    struct node *next_;
};

typedef struct node node_t;

struct clist
{
    node_t *current_;
};

typedef struct clist clist_t;

void init(clist_t *ptr_clist);
void add(clist_t *ptr_clist, int key);
void add_person(clist_t *ptr_clist, int key, const char *name);
void disp(clist_t *ptr_list);
void disp_people(clist_t *ptr_list);

void deinit(clist_t *ptr_list);
int delete(clist_t *ptr_clist);
void find_kth(clist_t *ptr_list, int k);
void find_kth_person(clist_t *ptr_list, int k, char *name, int *key);

#endif