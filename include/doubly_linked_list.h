#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct DLLElement
{
    int key;
    struct DLLElement *prev;
    struct DLLElement *next;
} DLLElement;

typedef struct
{
    DLLElement *head;
} DLL;

DLL* buildDLL();
DLLElement* buildDLLElement(int k);
void deleteDLL(DLL *L);
DLLElement* listSearch(DLL *L, int k);
void listInsert(DLL *L, DLLElement *x);
void listDelete(DLL *L, DLLElement *x);

#endif