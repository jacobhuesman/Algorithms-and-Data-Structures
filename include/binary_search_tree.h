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