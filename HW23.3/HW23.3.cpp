#include <iostream>
#include <stack>
#include <unordered_map>

bool areBracketsBalanced(const std::string& line)
{
    std::stack<char> stack;
    std::unordered_map<char, char> matchingBrackets = 
    {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };

    for (char ch : line) {
        if (ch == '(' || ch == '{' || ch == '[') 
        {
            stack.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') 
        {
            if (stack.empty() || stack.top() != matchingBrackets[ch])
            {
                return false;
            }
            stack.pop();
        }
    }

    return stack.empty();
}

int main() {
    std::string line = "{ [() ] }()";
    if (areBracketsBalanced(line)) 
    {
        std::cout << "OK" << std::endl;
    }
    else 
    {
        std::cout << "NOT OK" << std::endl;
    }

    line = "{ [ ( ) ] }";
    if (areBracketsBalanced(line)) 
    {
        std::cout << "OK" << std::endl;
    }
    else 
    {
        std::cout << "NOT OK" << std::endl;
    }

    return 0;
}