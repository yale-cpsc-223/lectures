#pragma once

class Stack
{
public:
    Stack();
    ~Stack();

    void push(int elem);
    int pop();
    bool isEmpty();

private:
    class node;
    node *top;
};
