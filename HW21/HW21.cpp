#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


bool compareByLength(const std::string& a, const std::string& b) {
    return a.size() < b.size();
}

int main() {
    std::vector<std::string> stringContainer = { "apple", "banana", "pear", "grapefruit", "kiwi" };

    std::sort(stringContainer.begin(), stringContainer.end(), compareByLength);

    for (const auto& str : stringContainer) {
        std::cout << str << " ";
    }

    return 0;
}
