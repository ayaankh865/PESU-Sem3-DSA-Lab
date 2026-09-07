#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clist.h"

void init(clist_t *ptr_clist)
{
    ptr_clist->current_ = NULL;
}

void add(clist_t *ptr_clist, int key)
{
    add_person(ptr_clist, key, "");
}

void add_person(clist_t *ptr_clist, int key, const char *name)
{
    node_t *temp = (node_t *)malloc(sizeof(node_t));

    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    temp->key_ = key;

    strncpy(temp->name_, name, NAME_SIZE - 1);
    temp->name_[NAME_SIZE - 1] = '\0';

    if (ptr_clist->current_ == NULL)
    {
        ptr_clist->current_ = temp;
        temp->next_ = temp;
    }
    else
    {
        temp->next_ = ptr_clist->current_->next_;
        ptr_clist->current_->next_ = temp;
        ptr_clist->current_ = temp;
    }
}

void disp(clist_t *ptr_clist)
{
    node_t *pres = ptr_clist->current_;

    if (pres != NULL)
    {
        do
        {
            pres = pres->next_;
            printf("%d ", pres->key_);
        }
        while (pres != ptr_clist->current_);
    }

    printf("\n");
}

void disp_people(clist_t *ptr_clist)
{
    node_t *pres = ptr_clist->current_;

    if (pres != NULL)
    {
        do
        {
            pres = pres->next_;

            if (pres->name_[0] != '\0')
            {
                printf("%d - %s\n", pres->key_, pres->name_);
            }
            else
            {
                printf("%d\n", pres->key_);
            }
        }
        while (pres != ptr_clist->current_);
    }
}

void deinit(clist_t *ptr_clist)
{
    node_t *current;
    node_t *temp;

    if (ptr_clist->current_ == NULL)
    {
        return;
    }

    current = ptr_clist->current_->next_;

    while (current != ptr_clist->current_)
    {
        temp = current;
        current = current->next_;
        free(temp);
    }

    free(ptr_clist->current_);
    ptr_clist->current_ = NULL;
}

int delete(clist_t *ptr_clist)
{
    node_t *temp;
    int key;

    if (ptr_clist->current_ == NULL)
    {
        return -1;
    }

    temp = ptr_clist->current_->next_;
    key = temp->key_;

    if (temp == ptr_clist->current_)
    {
        ptr_clist->current_ = NULL;
    }
    else
    {
        ptr_clist->current_->next_ = temp->next_;
    }

    free(temp);

    return key;
}

void find_kth(clist_t *ptr_list, int k)
{
    int i;

    if (ptr_list->current_ == NULL || k <= 0)
    {
        return;
    }

    for (i = 1; i < k; i++)
    {
        ptr_list->current_ = ptr_list->current_->next_;
    }

    delete(ptr_list);
}
void find_kth_person(clist_t *ptr_list, int k, char *name, int *key)
{
    int i;
    node_t *target;

    if (ptr_list->current_ == NULL || k <= 0)
    {
        return;
    }

    for (i = 1; i < k; i++)
    {
        ptr_list->current_ = ptr_list->current_->next_;
    }

    target = ptr_list->current_->next_;

    *key = target->key_;

    strncpy(name, target->name_, NAME_SIZE - 1);
    name[NAME_SIZE - 1] = '\0';

    delete(ptr_list);
}