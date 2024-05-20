
#include <iostream>
#include <cctype>

void parseStringLetters(const char str[], int& vowelsCount, int& constonantsCount)
{
    vowelsCount = 0;
    constonantsCount = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if ((std::isalpha(str[i])))
        {
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
            {
                vowelsCount++;
            }
            else
            {
                constonantsCount++;
            }
        }
    }
        std::cout << "Vowels : " << vowelsCount << "\n";
        std::cout << "Constonants : " << constonantsCount;
}

int main()
{
    int vowelsCount = 0, constonantsCount = 0;
    const int Size = 25;
    char inputLine[Size];
 
    std::cin.getline(inputLine, Size);
    parseStringLetters(inputLine, vowelsCount, constonantsCount);
}

