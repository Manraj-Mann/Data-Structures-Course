#include <iostream>
#include <stack>
#include <string>

struct Bracket
{
    Bracket(char type, int position) : type(type),
                                       position(position)
    {
    }

    bool Matchc(char c)
    {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main()
{
    std::string text;
    getline(std::cin, text);
    int mismatch = 0;
    std::stack<Bracket> opening_brackets_stack;
    int position = 0;
    for (position = 0; position < text.length(); ++position)
    {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{')
        {
            // Process opening bracket, write your code here

            opening_brackets_stack.push(Bracket(next, position+1));
        }

        if (next == ')' || next == ']' || next == '}')
        {
            // Process closing bracket, write your code here

            if (opening_brackets_stack.empty() == 1)
            {
                break;
            }

            if ((opening_brackets_stack.top()).Matchc(next) == 1)
            {
                opening_brackets_stack.pop();
            }
            else
            {
                mismatch = 1;
                break;
            }
        }
    }

    // Printing answer, write your code here

    if (opening_brackets_stack.empty() == 1 && position == text.length() )
    {

        std::cout << "Success";
    }
    else if ( (opening_brackets_stack.empty() == 1 && position != text.length()) || mismatch == 1 )
    {

        std::cout << position+1;
    }
    else 
    {
        std::cout << (opening_brackets_stack.top()).position;
    }

    return 0;
}
