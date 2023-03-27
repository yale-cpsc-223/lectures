#include "linked_stack.h"

#include <cassert>
#include <iostream>

class Stack::node
{
public:
    int payload;
    node *next;
    node(int payload)
    {
        this->payload = payload;
        this->next = nullptr;
    }
};

Stack::Stack()
{
    this->top = nullptr;
}

Stack::~Stack() = default;

void Stack::push(int elem)
{
    node *new_node = new node(elem);
    new_node->next = this->top;
    this->top = new_node;
}

int Stack::pop()
{
    assert(!this->isEmpty());
    try
    {
        node *topNode = this->top;
        this->top = topNode->next;
        int top = topNode->payload;
        topNode->next = nullptr;
        delete topNode;
        return top;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

bool Stack::isEmpty()
{
    return this->top == nullptr;
}
