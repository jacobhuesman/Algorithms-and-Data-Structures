#include <binary_search_tree.h>
#include <stdlib.h>

BSTNode* buildBSTNode(int key)
{
    BSTNode *x = (BSTNode*)malloc(sizeof(BSTNode));
    x->key = key;
    x->parent = NULL;
    x->left = NULL;
    x->right = NULL;
}

BST* buildBST(int root_key)
{
    BST *x = (BST*)malloc(sizeof(BST));
    x->root = buildBSTNode(root_key);
    x->size = 1;
}

void _deleteBST(BSTNode *x)
{
    if (x != NULL)
    {
        _deleteBST(x->left);
        _deleteBST(x->right);
        free(x);
    }
}

void deleteBST(BST *x)
{
    if (x != NULL)
    {
        _deleteBST(x->root);
        free(x);
    }
}

BSTNode* treeInsert(BST *T, int key)
{
    BSTNode *z = buildBSTNode(key);
    BSTNode *y = NULL;
    BSTNode *x = T->root;
    while (x != NULL)
    {
        y = x;
        if (z->key < x->key)
        {
            x = x->left;
        } 
        else
        {
            x = x->right;
        }
    }
    z->parent = y;
    if (y == NULL)
    {
        T->root = z;
    }
    else if (z->key < y->key)
    {
        y->left = z;
    }
    else
    {
        y->right = z;
    }
    return z;
}

BSTNode* _treeSearch(BSTNode *x, int key)
{
    if (x == NULL || key == x->key)
    {
        return x;
    }
    if (key < x->key)
    {
        return _treeSearch(x->left, key);
    }
    else
    {
        return _treeSearch(x->right, key);
    }
}


BSTNode* treeSearch(BST *x, int key)
{
    return _treeSearch(x->root, key); 
}

void _inorderTreeWalk(BSTNode *x, int *i, int *A)
{
    if (x != NULL)
    {
        _inorderTreeWalk(x->left, i, A);
        A[(*i)++] = x->key;
        _inorderTreeWalk(x->right, i, A);
    }
}

int* inorderTreeWalk(BST *x)
{
    int i = 0;
    int *A = (int*)malloc(sizeof(int)*x->size);
    if (x != NULL)
    {
        _inorderTreeWalk(x->root, &i, A);
    }
    return A;
}

BSTNode* _treeMinimum(BSTNode *x)
{
    while (x->left != NULL)
    {
        x = x->left;
    }
    return x;
}

BSTNode* treeMinimum(BST *T)
{
    return _treeMinimum(T->root);
}

BSTNode* _treeMaximum(BSTNode *x)
{
    while (x->right != NULL)
    {
        x = x->right;
    }
    return x;
}

BSTNode* treeMaximum(BST *T)
{
    return _treeMaximum(T->root);
}

BSTNode* treeSuccessor(BSTNode *x)
{
    if (x->right != NULL)
    {
        return _treeMinimum(x->right);
    }
    BSTNode *y = x->parent;
    while (y != NULL && x == y->right)
    {
        x = y;
        y = y->parent;
    }
    return y;
}














