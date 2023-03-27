#include "linked_stack.h"

#include <string>
#include <iostream>

bool is_open_sym(char c)
{
    return c == '(' || c == '{' || c == '[';
}

bool is_close_sym(char c)
{
    return c == ')' || c == '}' || c == ']';
}

bool are_matching_delimiters(char open, char closing)
{
    return (open == '(' && closing == ')') || (open == '{' && closing == '}') || (open == '[' && closing == ']');
}

bool string_has_balanced_parentheses(std::string exp)
{
    bool still_balanced = true;
    Stack s;
    for (size_t i = 0; i < exp.length() && still_balanced; i++)
    {
        char c = exp[i];
        if (is_open_sym(c))
        {
            s.push(c);
        }
        else if (is_close_sym(c))
        {
            if (s.isEmpty())
            {
                still_balanced = false;
            }
            else
            {
                char top = s.pop();
                still_balanced = are_matching_delimiters(top, c);
            }
        }
    }
    return still_balanced && s.isEmpty();
}

int main(int argc, char *argv[])
{
    bool is_balanced = string_has_balanced_parentheses(argv[1]);
    std::cout << argv[1] << " is" << (is_balanced ? " " : " not ")
              << "balanced." << std::endl;
}
