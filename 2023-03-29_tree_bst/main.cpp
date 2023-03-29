#include <iostream>

#include "tree.hpp"

void print_int(int x)
{
    std::cout << x << ' ';
}

int main(int argc, char *argv[])
{
    BST *tree = new BST(std::cin);

    std::cout << "IN ORDER TRAVERSAL:" << std::endl;
    tree->traverse(IN_ORDER, print_int);
    std::cout << std::endl
              << std::endl;

    std::cout << "PRE ORDER TRAVERSAL:" << std::endl;
    tree->traverse(PRE_ORDER, print_int);
    std::cout << std::endl
              << std::endl;

    std::cout << "POST ORDER TRAVERSAL:" << std::endl;
    tree->traverse(POST_ORDER, print_int);
    std::cout << std::endl
              << std::endl;

    std::cout << "PRETTY PRINT (height = " << tree->height() << ", size = " << tree->size() << "):" << std::endl;
    std::cout << tree << std::endl;

    bool _3_is_present = tree->search(3);
    bool _4_is_present = tree->search(4);

    std::cout << "SEARCH RESULTS:" << std::endl;
    std::cout << "3? " << _3_is_present << std::endl;
    std::cout << "4? " << _4_is_present << std::endl
              << std::endl;

    std::cout << "AFTER REMOVE 2:" << std::endl;
    tree->remove(2);
    std::cout << tree << std::endl
              << std::endl;

    std::cout << "AFTER REMOVE 8:" << std::endl;
    tree->remove(8);
    std::cout << tree << std::endl
              << std::endl;

    std::cout << "AFTER REMOVE 3:" << std::endl;
    tree->remove(3);
    std::cout << tree << std::endl
              << std::endl;

    delete tree;
}