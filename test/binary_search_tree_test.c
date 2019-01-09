#include <binary_search_tree.h>
#include <eval.h>

void tests()
{
    TEST(buildBSTNode);
    {
        BSTNode *x = buildBSTNode(5);
        ASSERT(x->key == 5);
        ASSERT(x->parent == NULL);
        ASSERT(x->left == NULL);
        ASSERT(x->right == NULL);
        free(x);
    }
    
    TEST(buildBST);
    {
        BST *x = buildBST(5);
        ASSERT(x->root->key == 5);
        ASSERT(x->size == 1);
        free(x->root);
        free(x);
    }

    TEST(inorderTreeWalk);
    {
        int E[] = {3,4,5,6,7};
        BST *x = buildBST(5);
        x->root->left = buildBSTNode(3);
        x->root->right = buildBSTNode(7);
        x->root->left->right = buildBSTNode(4);
        x->root->right->left = buildBSTNode(6);
        int *A = inorderTreeWalk(x);
        ASSERT_ARRAY_EQ(5, A, E);
        deleteBST(x);
    }

    TEST(treeInsert);
    {
        int E[] = {1,2,3,4,5,6,7,8,9};
        BST *x = buildBST(5);
        treeInsert(x, 1);
        treeInsert(x, 3);
        treeInsert(x, 4);
        treeInsert(x, 2);
        treeInsert(x, 8);
        treeInsert(x, 7);
        BSTNode *t = treeInsert(x, 9);
        treeInsert(x, 6);
        int *A = inorderTreeWalk(x);
        ASSERT(t->key == 9);
        ASSERT(t->parent->key == 8);
        ASSERT(t->left == NULL);
        ASSERT(t->right == NULL);
        ASSERT_ARRAY_EQ(5, A, E);
        deleteBST(x);
    }

    TEST(treeSearch);
    {
        BST *x = buildBST(5);
        treeInsert(x, 3);
        treeInsert(x, 1);
        treeInsert(x, 4);
        treeInsert(x, 8);
        treeInsert(x, 6);
        ASSERT(treeSearch(x, 3)->key == 3);
        ASSERT(treeSearch(x, 3)->parent->key == 5);
        ASSERT(treeSearch(x, 3)->left->key == 1);
        ASSERT(treeSearch(x, 3)->right->key == 4);
        ASSERT(treeSearch(x, 1)->key == 1);
        ASSERT(treeSearch(x, 1)->parent->key == 3);
        ASSERT(treeSearch(x, 1)->left == NULL);
        ASSERT(treeSearch(x, 1)->right == NULL);
        ASSERT(treeSearch(x, 6)->key == 6);
        deleteBST(x);
    }

    TEST(treeMinimum)
    {
        BST *x = buildBST(5);
        treeInsert(x, 3);
        treeInsert(x, 4);
        treeInsert(x, 1);
        treeInsert(x, 2);
        treeInsert(x, 8);
        treeInsert(x, 7);
        treeInsert(x, 9);
        treeInsert(x, 6);
        ASSERT(treeMinimum(x)->key == 1);
        deleteBST(x);
    }

    TEST(treeMaximum)
    {
        BST *x = buildBST(5);
        treeInsert(x, 3);
        treeInsert(x, 4);
        treeInsert(x, 1);
        treeInsert(x, 2);
        treeInsert(x, 8);
        treeInsert(x, 7);
        treeInsert(x, 9);
        treeInsert(x, 6);
        ASSERT(treeMaximum(x)->key == 9);
        deleteBST(x);
    }

    TEST(treeSuccessor)
    {
        BST *x = buildBST(5);
        treeInsert(x, 3);
        treeInsert(x, 4);
        treeInsert(x, 1);
        treeInsert(x, 2);
        treeInsert(x, 8);
        treeInsert(x, 7);
        treeInsert(x, 9);
        treeInsert(x, 6);
        ASSERT(treeSuccessor(treeSearch(x, 7))->key == 8);
        deleteBST(x);
    }
}


void main()
{
    printf("\n" "Running: %s\n", __FILE__);
    tests();
    printf("\n");
}