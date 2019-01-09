#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

typedef struct BSTNode
{
    int key;
    struct BSTNode *parent;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

typedef struct
{
    BSTNode *root;
    int size;
} BST;

BSTNode* buildBSTNode(int key);
BST* buildBST(int root_key);
void deleteBST(BST *T);
BSTNode* treeSearch(BST *T, int key);
int* inorderTreeWalk(BST *T);
BSTNode* treeMinimum(BST *T);
BSTNode* treeMaximum(BST *T);
BSTNode* treeSuccessor(BSTNode *x);
BSTNode* treeInsert(BST *T, int key);

#endif // BINARY_SEARCH_TREE_H