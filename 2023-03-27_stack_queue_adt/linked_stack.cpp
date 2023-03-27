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

    ~node()
    {
        delete this->next;
    }
};

Stack::Stack()
{
    this->top = nullptr;
}

Stack::~Stack()
{
    delete this->top;
}

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

/*****************
 * MAIN FUNCTION *
 *****************/

int main()
{
    Stack s;

    std::string input;
    std::getline(std::cin, input);
    while (!input.empty())
    {
        int x = std::stoi(input);
        s.push(x);
        std::getline(std::cin, input);
    }

    while (!s.isEmpty())
    {
        int next = s.pop();
        std::cout << next << std::endl;
    }
}
