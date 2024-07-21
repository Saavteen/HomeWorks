#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class LengthComparator 
{
public:
    bool operator()(const std::string& a, const std::string& b) const 
    {
        return a.size() < b.size();
    }
};

int main() {
    std::vector<std::string> stringContainer = { "apple", "banana", "pear", "grapefruit", "kiwi" };

    std::sort(stringContainer.begin(), stringContainer.end(), LengthComparator());

    for (const auto& str : stringContainer) 
    {
        std::cout << str << " ";
    }

    return 0;
}
