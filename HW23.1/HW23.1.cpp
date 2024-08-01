#include <iostream>
#include <unordered_set>
#include <sstream>

unsigned int uniqueWordsCount(const std::string& line) {
    std::unordered_set<std::string> uniqueWords;
    std::stringstream ss(line);
    std::string word;

    while (ss >> word) {
        uniqueWords.insert(word);
    }

    return uniqueWords.size();
}

int main() {
    std::string line = "Hello Hey Hello Bye Hey";
    std::cout << "Unique words count: " << uniqueWordsCount(line) << std::endl;
    return 0;
}
