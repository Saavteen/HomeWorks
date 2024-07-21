#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() 
{
    std::vector<std::string> stringContainer = { "apple", "banana", "pear", "grapefruit", "kiwi" };

    std::sort(stringContainer.begin(), stringContainer.end(), [](const std::string& a, const std::string& b) 
        {
        return a.size() < b.size();
        });

    for (const auto& str : stringContainer) 
    {
        std::cout << str << " ";
    }

    return 0;
}
