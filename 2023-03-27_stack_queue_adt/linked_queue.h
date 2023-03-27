#pragma once

class Queue
{
public:
    Queue();
    ~Queue();

    void enqueue(int elem);
    int dequeue();
    bool isEmpty();

private:
    class node;
    node *head;
    node *tail;
};
