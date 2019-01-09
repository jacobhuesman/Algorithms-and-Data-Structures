#include <doubly_linked_list.h>
#include <stdlib.h>

DLL* buildDLL()
{
    DLL *L = (DLL*)malloc(sizeof(DLL));
    L->head = NULL;
}

DLLElement* buildDLLElement(int k)
{
    DLLElement *x = (DLLElement*)malloc(sizeof(DLLElement));
    x->key = k;
    x->prev = NULL;
    x->next = NULL;
    return x;
}

void deleteDLL(DLL *L)
{
    if (L->head != NULL)
    {
        DLLElement *x = L->head;
        while(x->next != NULL)
        {
            x = x->next;
            free(x->prev);
        }
        free(x);
    }
    if (L != NULL)
    {
        free(L);
    }
}

DLLElement* listSearch(DLL *L, int k)
{
    DLLElement *x = L->head;
    while (x != NULL && x->key != k)
    {
        x = x->next;
    }
    return x;
}

void listInsert(DLL *L, DLLElement *x)
{
    if (L->head != NULL)
    {
        L->head->prev = x;
    }
    x->prev = NULL;
    x->next = L->head;
    L->head = x;
}

void listDelete(DLL *L, DLLElement *x)
{
    if (x->prev != NULL)
    {
        x->prev->next = x->next;
    }
    else
    {
        L->head = x->next;
    }
    if (x->next != NULL)
    {
        x->next->prev = x->prev;
    }
}