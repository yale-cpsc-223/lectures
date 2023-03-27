#include "circular_queue.h"

#include <string>
#include <iostream>
#include <cassert>

#define INITIAL_CAPACITY 8
#define RESIZE_FACTOR 2

Queue::Queue()
{
    this->q.resize(INITIAL_CAPACITY);
    this->head = 0;
    this->post_tail = 0;
}

Queue::~Queue() = default;

void Queue::enqueue(int elem)
{
    this->resize_if_necessary();
    this->q[this->post_tail] = elem;
    this->post_tail = (this->post_tail + 1) % this->q.capacity();
}

int Queue::dequeue()
{
    assert(!this->isEmpty());
    this->resize_if_necessary();
    int val = this->q[this->head];
    this->head = (this->head + 1) % this->q.capacity();
    return val;
}

bool Queue::isEmpty()
{
    return this->head == this->post_tail;
}

size_t Queue::length()
{
    return ((this->post_tail + this->q.capacity()) - this->head) % this->q.capacity();
}

void Queue::resize_if_necessary()
{
    size_t new_cap = this->q.capacity();
    if (this->length() + 1 == this->q.capacity())
    {
        new_cap *= RESIZE_FACTOR;
    }
    else if (this->q.capacity() > INITIAL_CAPACITY && this->length() * RESIZE_FACTOR < this->q.capacity() / RESIZE_FACTOR)
    {
        new_cap /= RESIZE_FACTOR;
    }
    if (new_cap != this->q.capacity())
    {
        std::vector<int> new_q;
        new_q.resize(new_cap);
        this->post_tail = this->length();
        for (size_t i = 0; i < this->post_tail; i++)
        {
            new_q[i] = this->q[(i + this->head) % this->q.capacity()];
        }
        this->head = 0;
        this->q = new_q;
    }
}
