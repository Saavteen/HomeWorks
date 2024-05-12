
#include <iostream>
#include <cctype>

int main()
{
    char symbol;
    int summary = 0;
    std::cout << "Enter your symbol :\n";
    while (true)
    {
    std::cin >> symbol;

        
        //letter
        if (isalpha(symbol))
        {
            if (islower(symbol))
            {
                symbol = std::toupper(symbol);
                std::cout << symbol;
            }
            else if (isupper(symbol))
            {
                symbol = std::tolower(symbol);
                std::cout << symbol;
            }
        }
        //number
        else if (isdigit(symbol))
        {
            int numbers = symbol - '0';
            summary += numbers;
            std::cout << summary << "\n";
        }
        //spec symbol
        else if (ispunct(symbol))
        {
            std::cout << "Program dont support this type of symbol";
        }
        //Exit
        else if (symbol == '.')
        {
            break;
        }
        //Eror
        else
        {
            std::cout << "Eror try again";
        }
    }
return 0;
}

