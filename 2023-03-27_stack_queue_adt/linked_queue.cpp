#include "linked_queue.h"

#include <cassert>
#include <iostream>

class Queue::node
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

Queue::Queue()
{
    this->head = nullptr;
    this->tail = nullptr;
}

Queue::~Queue() = default;

void Queue::enqueue(int elem)
{
    node *new_node = new node(elem);
    if (this->isEmpty())
    {
        this->head = new_node;
    }
    else
    {
        this->tail->next = new_node;
    }
    this->tail = new_node;
}

int Queue::dequeue()
{
    assert(!this->isEmpty());
    try
    {
        node *hdNode = this->head;
        if (this->head == this->tail)
        {
            assert(hdNode->next == nullptr);
            this->tail = hdNode->next;
        }
        this->head = hdNode->next;
        int head = hdNode->payload;
        hdNode->next = nullptr;
        delete hdNode;
        return head;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

bool Queue::isEmpty()
{
    return this->head == nullptr;
}
