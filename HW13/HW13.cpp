#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cctype>


/*void getWordOfTheDay()
{
    std::time_t t = std::time(0);
    std::tm now;
    if (localtime_s(&now, &t) != 0)
    {
        std::cout << "Failed to get local time" << std::endl;
        return "";
    }

    int dayOfYear = now.tm_yday;
    
}
*/
void readFile(const char* fileName, std::string& mysteryWord,const int maxWord)
{
    std::fstream file;
    file.open(fileName, std::ios::in);
    if (!file)
    {
        std::cout << "Eror file not found";
        return;
    }
    else
    {
        std::string word;
        int count = 0;

        std::srand(static_cast<unsigned int>(std::time(0)));
        int randomNumber = std::rand() % maxWord + 1;

        for (int i = 0 ; i < randomNumber;i++)
        {
            getline(file, word);
        }
        mysteryWord = word;
        //std::cout << mysteryWord;
        file.close();
    }
}

void compareWords(std::string& yourWord, const std::string& mysteryWord, std::string& currentWord, int maxTries)
{
    for (int tries = 0; tries <= maxTries; tries++)
    {
        std::cout << "\nEnter : ";
        std::cin >> yourWord;
        std::cout << "Result : ";
        if (yourWord == mysteryWord)
        {
            std::cout << "you win !!!\nused tries " << tries<<std::endl;
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
                if (!found) {
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
    int maxTries = 5;
    int choice;
    const int maxWords = 50;

    std::string mysteryWord;
    std::string yourWord; 
    std::string currentWord = "*****";

    std::cout << "Let's play" << std::endl;

    do 
    {
        std::cout << "\nMenu:" << std::endl;
        std::cout << "1. Option 1" << std::endl;
        std::cout << "2. Option 2" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) 
        {
        case 1:
            readFile("data_base.txt", mysteryWord, maxWords);
            compareWords(yourWord, mysteryWord, currentWord, maxTries);
            break;
        case 2:
            //to do getWordOfDay
            readFile("data_base.txt", mysteryWord, maxWords);
            break;
        case 0:
            std::cout << "Exiting..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    } 
    while (choice != 0);

    return 0;
}
   