
#include <iostream>
#include <string>
#include <cctype>

void compareWords(std::string& yourWord, const std::string& mysteryWord, std::string& currentWord,int maxTries)
{
    for (int tries = 0; tries <= maxTries; tries++)
    {
        std::cout << "\nEnter : ";
        std::cin >> yourWord;
        std::cout << "Result : ";
        if (yourWord == mysteryWord)
        {
            std::cout << "you win !!!\n used tries " << tries;
            return;
        }

        for (int i = 0; i <= maxTries; i++)
        {
            if (yourWord[i] == mysteryWord[i])
            {
                currentWord[i] = mysteryWord[i];
                std::cout << static_cast<char>(std::toupper(currentWord[i]));
            }
            else
            {
                bool found = false;
                for (int j = 0; j <= maxTries; j++)
                {
                    if (yourWord[i] == mysteryWord[j])
                    {
                        currentWord[i] = yourWord[i];
                        std::cout << static_cast<char>(std::tolower(currentWord[i]));
                        found = true;
                        break;
                    }
                }
                if (!found)                {
                    std::cout << "*";
                }
            }
        }
        std::cout << std::endl;
    }
    std::cout << "you lose ((\ntry one more time";
}

int main()
{
    std::string mysteryWord = "chair";
    std::string yourWord,currentWord="*****";
    int maxTries = 5;

    std::cout << "Let's play"<<std::endl;

    compareWords(yourWord, mysteryWord, currentWord, maxTries);
}




