#include <iostream>
#include <unordered_map>
#include <sstream>

std::string mostOccuredWord(const std::string& line) 
{
    std::unordered_map<std::string, int> wordCount;
    std::stringstream ss(line);
    std::string word;

    while (ss >> word)
    {
        wordCount[word]++;
    }

    std::string mostFrequentWord;
    int maxCount = 0;

    for (const auto& pair : wordCount)
    {
        if (pair.second > maxCount)
        {
            mostFrequentWord = pair.first;
            maxCount = pair.second;
        }
    }

    return mostFrequentWord;
}

int main() 
{
    std::string line = "Hello Hey Hello Bye Hey";
    std::cout << "Most occurred word: " << mostOccuredWord(line) << std::endl;
    return 0;
}
