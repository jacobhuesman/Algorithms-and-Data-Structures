/*
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

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