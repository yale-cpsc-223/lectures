#pragma once

#include <iostream>
enum Order
{
    IN_ORDER,
    PRE_ORDER,
    POST_ORDER
};

class BSTNode;

/* Class for a Binary Search Tree of ints. */
class BST
{
public:
    BST();
    BST(std::istream &in);
    ~BST();

    /* Traverse a BST with the given order, calling function visit at each node. */
    void traverse(Order order, std::function<void(int)> visit) const;

    /* Reports the height of the BST. */
    size_t height() const;

    /* Reports the number of nodes in this BST. */
    size_t size() const;

    /* Search for x in the BST and report whether it is present. */
    bool search(int x) const;

    /* Insert x into the BST. */
    void insert(int x);

    /* Remove x from the BST. */
    void remove(int x);

    /* Pretty-prints the tree. */
    friend std::ostream &operator<<(std::ostream &os, const BST *tree);

private:
    BSTNode *root;
};
