#include <iostream>

#include "tree.hpp"

void print_int(int x)
{
    std::cout << x << '\n';
}

int main(int argc, char *argv[])
{
    BST *tree = new BST(std::cin);

    std::cout << "PRETTY PRINT:" << std::endl
              << *tree << std::endl;

    std::cout << "IN ORDER TRAVERSAL:" << std::endl;
    tree->traverse(IN_ORDER, print_int);
    std::cout << std::endl;

    std::cout << "PRE ORDER TRAVERSAL:" << std::endl;
    tree->traverse(PRE_ORDER, print_int);
    std::cout << std::endl;

    std::cout << "POST ORDER TRAVERSAL:" << std::endl;
    tree->traverse(POST_ORDER, print_int);
    std::cout << std::endl;

    delete tree;
}