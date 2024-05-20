#include <cstring>
#include <iostream>
#include <cctype>


bool isPalindrom(const char str[], int lineSize) 
{
    int length = strlen(str);
    int i = 0, j = length-1 ;
    while (i < j) 
    {
        if ((str[i]) != (str[j])) 
        {
            std::cout << "error";
            return false;
        }
        i++;
        j--;
    }
    std::cout << "success\n" << str;
    return true;
}

int main() {
    const int lineSize = 25;
    char line[lineSize];
    std::cin.getline(line, lineSize);
    isPalindrom(line, lineSize);
}



