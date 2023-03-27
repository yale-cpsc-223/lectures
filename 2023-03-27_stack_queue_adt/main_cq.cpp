#include <iostream>

#include "circular_queue.h"

int main()
{
    Queue s;

    std::string input;
    std::getline(std::cin, input);
    while (!input.empty())
    {
        int x = std::stoi(input);
        s.enqueue(x);
        std::getline(std::cin, input);
    }

    while (!s.isEmpty())
    {
        int next = s.dequeue();
        std::cout << next << std::endl;
    }
}
