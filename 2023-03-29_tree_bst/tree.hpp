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
    void traverse(Order order, std::function<void(int)> visit);

    /* Reports the height of the BST. */
    size_t height();

    /* Reports the numbe of nodes in this BST. */
    size_t size();

    /* Search for x in the BST and report whether it is present. */
    bool search(int x);

    /* Insert x into the BST. */
    void insert(int x);

    /* Remove x from the BST. */
    void remove(int x);

    void pretty_print(std::ostream &os) const;

    friend std::ostream &operator<<(std::ostream &os, const BST &tree);

private:
    BSTNode *root;
};
