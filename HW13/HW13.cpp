#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cctype>

int dayOfYear = 1;
int currentData = 1;
bool currentDay = false;

void getWordOfTheDay(const char* fileName)
{
    currentDay = true;
    std::time_t t = std::time(0);
    std::tm now;
    if (localtime_s(&now, &t) != 0)
    {
        std::cout << "Failed to get local time" << std::endl;
        return;
    }

    dayOfYear = now.tm_yday;

    std::fstream file;
    file.open(fileName, std::ios::out);

    currentData = dayOfYear;
    if (!file)
    {
        std::cout << "eror missing file\n";
    }
    else
    {
        file << currentData;
        file.close();
    }

}

bool isNewDay(const char* fileName) {
    std::ifstream file(fileName);
    if (!file) 
    {
        return true; 
    }

    int lastRecordedDay;
    file >> lastRecordedDay;
    file.close();

    std::time_t t = std::time(0);
    std::tm now;
    localtime_s(&now, &t);

    dayOfYear = now.tm_yday;
    return dayOfYear != lastRecordedDay;
}

void readFile(const char* fileName, std::string& mysteryWord,const int maxWord)
{
    std::fstream file;
    file.open(fileName, std::ios::in);
    if (!file)
    {
        std::cout << "Eror file not found";
        return;
    }
    else if (currentDay==true)
    {
        if (isNewDay("current_data.txt"))
        {
            std::fstream file;
            file.open(fileName, std::ios::in);
            if (!file) 
            {
                std::cout << "Error: file not found\n";
                return;
            }
            
            std::string word;
            int count = 0;
            int linesToRead = dayOfYear < 31 ? dayOfYear : dayOfYear / 31;

            for (int j = 0; j < linesToRead; j++) {
                if (!getline(file, word)) break;
            }

            mysteryWord = word;
            file.close();
            getWordOfTheDay("current_data.txt"); // Записати поточний день у файл
        }
        else 
        {
            std::cout << "come back tomorrow";
            file.close();
            return;
        }
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
    int maxTries = 4;
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
            getWordOfTheDay("current_data.txt");
            readFile("data_base_day_word.txt", mysteryWord, maxWords);
            compareWords(yourWord, mysteryWord, currentWord, maxTries);
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
   