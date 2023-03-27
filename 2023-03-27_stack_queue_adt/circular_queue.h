#pragma once

#include <cstddef>
#include <vector>

class Queue
{
public:
    Queue();
    ~Queue();

    void enqueue(int elem);
    int dequeue();
    bool isEmpty();

private:
    size_t length();
    void resize_if_necessary();

    std::vector<int> q;
    size_t head;
    size_t post_tail;
};
