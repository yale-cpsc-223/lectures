#include <iostream>
#include <vector>

#include "linked_stack.h"

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
